#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <vector>

class Warehouse
{
private:
    int rows;
    int cols;

    std::vector<std::vector<int>> grid;

public:
    Warehouse(int r, int c);

    void addObstacle(int x, int y);

    bool isBlocked(int x, int y) const;

    bool isValid(int x, int y) const;

    void display(int robotX = -1, int robotY = -1) const;

    int getRows() const;

    int getCols() const;
};

#endif
