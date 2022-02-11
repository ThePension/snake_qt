#include "snakeblock.h"

SnakeBlock::SnakeBlock(int x, int y)
{
    this->X = x;
    this->Y = y;
}

void SnakeBlock::updatePosition(int x, int y)
{
    // checkdeath
    qDebug() << this->X << " ; " << this->Y;

    int oldX = this->X;
    int oldY = this->Y;

    this->X += x;
    this->Y += y;

    if(this->nextSnakeBlock == nullptr) { // If this block is tail
        // Add new tail
        this->nextSnakeBlock = new SnakeBlock(oldX, oldY);
    }else{

        this->nextSnakeBlock->eatApple();
    }
    this->isEating = false;
}

void SnakeBlock::eatApple()
{
    this->isEating = true;
}
