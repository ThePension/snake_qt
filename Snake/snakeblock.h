#ifndef SNAKEBLOCK_H
#define SNAKEBLOCK_H

#include <QDebug>

class SnakeBlock
{
public:
    SnakeBlock(int x, int y);

    int X;
    int Y;

    SnakeBlock * nextSnakeBlock = nullptr;

    void updatePosition(int x, int y);
    void eatApple();

    bool isEating = false;
};

#endif // SNAKEBLOCK_H
