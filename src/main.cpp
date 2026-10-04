#include <iostream>
#include <vector>

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

    // Create a 10 x 10 warehouse
    Warehouse warehouse(10, 10);

    // Add warehouse obstacles
    warehouse.addObstacle(1, 2);
    warehouse.addObstacle(2, 2);
    warehouse.addObstacle(3, 2);

    warehouse.addObstacle(4, 4);
    warehouse.addObstacle(5, 4);
    warehouse.addObstacle(6, 4);

    warehouse.addObstacle(7, 6);
    warehouse.addObstacle(7, 7);
    warehouse.addObstacle(7, 8);

    // Robot starting position
    int startX = 0;
    int startY = 0;

    // Destination
    int goalX = 9;
    int goalY = 9;

    Robot robot(startX, startY);

    std::cout << "Initial Warehouse:\n\n";

    warehouse.display(
        robot.getX(),
        robot.getY()
    );

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
              << path.size()
              << "\n\n";

    Logger::log("Path successfully found");

    std::cout << "Robot movement:\n\n";

    for (const auto& position : path)
    {
        robot.setPosition(
            position.first,
            position.second
        );

        std::cout
            << "Robot -> ("
            << robot.getX()
            << ", "
            << robot.getY()
            << ")\n";
    }

    std::cout << "\nDestination reached!\n";

    Logger::log("Robot reached destination");

    return 0;
}
