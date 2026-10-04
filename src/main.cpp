#include <iostream>
#include <vector>
#include <utility>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <cstring>

#include "warehouse.h"
#include "robot.h"
#include "pathfinder.h"
#include "logger.h"

int main()
{
    std::cout << "=====================================\n";
    std::cout << " AUTONOMOUS WAREHOUSE ROBOT SYSTEM\n";
    std::cout << "=====================================\n\n";

    Logger::log("Program started");

    // ---------------------------------------
    // 1. Create warehouse
    // ---------------------------------------

    Warehouse warehouse(10, 10);

    warehouse.addObstacle(1, 2);
    warehouse.addObstacle(2, 2);
    warehouse.addObstacle(3, 2);

    warehouse.addObstacle(4, 4);
    warehouse.addObstacle(5, 4);
    warehouse.addObstacle(6, 4);

    warehouse.addObstacle(7, 6);
    warehouse.addObstacle(7, 7);
    warehouse.addObstacle(7, 8);

    int startX = 0;
    int startY = 0;

    int goalX = 9;
    int goalY = 9;

    Robot robot(startX, startY);

    std::cout << "Initial Warehouse:\n\n";

    warehouse.display(robot.getX(), robot.getY());

    // ---------------------------------------
    // 2. Find path using BFS
    // ---------------------------------------

    std::cout << "\nFinding path...\n";

    std::vector<std::pair<int, int>> path =
        PathFinder::findPath(
            warehouse,
            startX,
            startY,
            goalX,
            goalY
        );

    if (path.empty())
    {
        std::cout << "No path found.\n";
        Logger::log("No path found");
        return 1;
    }

    std::cout << "\nPath found!\n";
    std::cout << "Number of steps: "
              << path.size() << "\n\n";

    Logger::log("Path successfully found");

    // ---------------------------------------
    // 3. Create pipe
    // ---------------------------------------

    int pipeFD[2];

    if (pipe(pipeFD) == -1)
    {
        std::cerr << "Pipe creation failed.\n";
        return 1;
    }

    // ---------------------------------------
    // 4. Create child process
    // ---------------------------------------

    pid_t processID = fork();

    if (processID == -1)
    {
        std::cerr << "Fork failed.\n";
        return 1;
    }

    // =======================================
    // CHILD PROCESS
    // =======================================

    if (processID == 0)
    {
        close(pipeFD[1]);

        std::cout << "\n[Child] Monitoring process started.\n";
        std::cout << "[Child] PID: "
                  << getpid() << "\n\n";

        char buffer[100];

        while (true)
        {
            ssize_t bytesRead =
                read(pipeFD[0], buffer, sizeof(buffer) - 1);

            if (bytesRead <= 0)
            {
                break;
            }

            buffer[bytesRead] = '\0';

            std::cout << "[Child Monitor] "
                      << buffer << std::endl;
        }

        close(pipeFD[0]);

        std::cout << "\n[Child] Monitoring finished.\n";

        return 0;
    }

    // =======================================
    // PARENT PROCESS
    // =======================================

    else
    {
        close(pipeFD[0]);

        std::cout << "\n[Parent] Robot controller started.\n";
        std::cout << "[Parent] PID: "
                  << getpid() << "\n";

        std::cout << "[Parent] Child PID: "
                  << processID << "\n\n";

        // -----------------------------------
        // 5. Move robot
        // -----------------------------------

        for (const auto& position : path)
        {
            robot.setPosition(
                position.first,
                position.second
            );

            std::cout << "[Parent] Robot -> ("
                      << robot.getX()
                      << ", "
                      << robot.getY()
                      << ")\n";

            // Create message
            char message[100];

            snprintf(
                message,
                sizeof(message),
                "Robot position: (%d, %d)",
                robot.getX(),
                robot.getY()
            );

            // Send message through pipe
            write(
                pipeFD[1],
                message,
                strlen(message)
            );

            // Send newline
            char newline = '\n';

            write(
                pipeFD[1],
                &newline,
                1
            );

            sleep(1);
        }

        close(pipeFD[1]);

        // -----------------------------------
        // 6. Wait for child process
        // -----------------------------------

        waitpid(processID, nullptr, 0);

        std::cout << "\nDestination reached!\n";

        Logger::log(
            "Robot reached destination"
        );
    }

    return 0;
}
