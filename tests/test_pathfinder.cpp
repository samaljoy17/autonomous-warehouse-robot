#include <iostream>
#include <cassert>

#include "../include/warehouse.h"
#include "../include/pathfinder.h"

int main() {

    Warehouse warehouse(5, 5);

    auto path = PathFinder::findPath(
        warehouse,
        0, 0,
        4, 4
    );

    assert(!path.empty());

    std::cout
        << "Test 1 passed: Basic pathfinding\n";

    Warehouse blocked(5, 5);

    blocked.addObstacle(1, 0);
    blocked.addObstacle(0, 1);

    auto noPath = PathFinder::findPath(
        blocked,
        0, 0,
        4, 4
    );

    assert(noPath.empty());

    std::cout
        << "Test 2 passed: Blocked path detection\n";

    Warehouse obstacleTest(5, 5);

    obstacleTest.addObstacle(2, 2);

    assert(obstacleTest.isBlocked(2, 2));

    std::cout
        << "Test 3 passed: Obstacle detection\n";

    std::cout
        << "\nAll tests passed.\n";

    return 0;
}
