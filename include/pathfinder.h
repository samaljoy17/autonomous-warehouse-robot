#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <vector>
#include <utility>

class Warehouse;

class PathFinder
{
public:

    static std::vector<std::pair<int, int>>
    findPath(
        const Warehouse& warehouse,
        int startX,
        int startY,
        int goalX,
        int goalY
    );
};

#endif
