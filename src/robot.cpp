#include "robot.h"

Robot::Robot(int startX, int startY)
{
    x = startX;
    y = startY;
}

void Robot::setPosition(int newX, int newY)
{
    x = newX;
    y = newY;
}

int Robot::getX() const
{
    return x;
}

int Robot::getY() const
{
    return y;
}
