#include "pathfinder.h"
#include "warehouse.h"

#include <queue>
#include <map>
#include <algorithm>

std::vector<std::pair<int, int>>
PathFinder::findPath(
    const Warehouse& warehouse,
    int startX,
    int startY,
    int goalX,
    int goalY)
{
    using Point = std::pair<int, int>;

    std::queue<Point> queue;

    std::map<Point, Point> parent;

    Point start = {startX, startY};
    Point goal = {goalX, goalY};

    queue.push(start);

    parent[start] = {-1, -1};

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!queue.empty())
    {
        Point current = queue.front();

        queue.pop();

        if (current == goal)
        {
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int nextX = current.first + dx[i];
            int nextY = current.second + dy[i];

            Point next = {nextX, nextY};

            if (!warehouse.isValid(nextX, nextY))
            {
                continue;
            }

            if (warehouse.isBlocked(nextX, nextY))
            {
                continue;
            }

            if (parent.find(next) != parent.end())
            {
                continue;
            }

            parent[next] = current;

            queue.push(next);
        }
    }

    if (parent.find(goal) == parent.end())
    {
        return {};
    }

    std::vector<Point> path;

    Point current = goal;

    while (current != Point{-1, -1})
    {
        path.push_back(current);

        current = parent[current];
    }

    std::reverse(path.begin(), path.end());

    return path;
}
