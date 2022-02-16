#ifndef SNAKEBLOCK_H
#define SNAKEBLOCK_H

#include <QDebug>
#include <QWidget>
#include <QPainter>

class SnakeBlock
{
public:
    SnakeBlock(int x, int y, bool isHead = false);

    int X;
    int Y;

    bool isHead = false;

    SnakeBlock * nextSnakeBlock = nullptr;

    void updatePosition(int x, int y);
    void eatApple();
    void draw(QPainter *, int blockSize);
    bool checkCollision(int otherX, int otherY);

    bool isEating = false;
};

#endif // SNAKEBLOCK_H
