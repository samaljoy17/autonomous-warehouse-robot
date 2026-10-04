#include "warehouse.h"

#include <iostream>

Warehouse::Warehouse(int r, int c)
{
    rows = r;
    cols = c;

    grid.resize(rows, std::vector<int>(cols, 0));
}

void Warehouse::addObstacle(int x, int y)
{
    if (isValid(x, y))
    {
        grid[x][y] = 1;
    }
}

bool Warehouse::isBlocked(int x, int y) const
{
    if (!isValid(x, y))
    {
        return true;
    }

    return grid[x][y] == 1;
}

bool Warehouse::isValid(int x, int y) const
{
    return x >= 0 &&
           x < rows &&
           y >= 0 &&
           y < cols;
}

void Warehouse::display(int robotX, int robotY) const
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i == robotX && j == robotY)
            {
                std::cout << " R ";
            }
            else if (grid[i][j] == 1)
            {
                std::cout << " # ";
            }
            else
            {
                std::cout << " . ";
            }
        }

        std::cout << std::endl;
    }
}

int Warehouse::getRows() const
{
    return rows;
}

int Warehouse::getCols() const
{
    return cols;
}
