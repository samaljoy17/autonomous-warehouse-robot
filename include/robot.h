#ifndef ROBOT_H
#define ROBOT_H

class Robot
{
private:
    int x;
    int y;

public:
    Robot(int startX, int startY);

    void setPosition(int newX, int newY);

    int getX() const;

    int getY() const;
};

#endif
