#include "snakeblock.h"

SnakeBlock::SnakeBlock(int x, int y)
{
    this->X = x;
    this->Y = y;
}

void SnakeBlock::updatePosition(int newPosX, int newPosY)
{
    // checkdeath


    int oldPosX = this->X;
    int oldPosY = this->Y;

    this->X = newPosX;
    this->Y = newPosY;

    if(this->isEating){
        if(this->nextSnakeBlock == nullptr) { // If this block is tail
            // Add new tail
            this->nextSnakeBlock = new SnakeBlock(oldPosX, oldPosY);
        }else{

            this->nextSnakeBlock->eatApple();
        }
    }
    else{ // Update next block position
        if(this->nextSnakeBlock != nullptr) { // If this block is not a tail
            // Add new tail
            this->nextSnakeBlock->updatePosition(oldPosX, oldPosY);
        }
    }


}

void SnakeBlock::eatApple()
{
    this->isEating = true;
}

void SnakeBlock::draw(QPainter * painter)
{
    painter->setRenderHint(QPainter::Antialiasing);
    if(this->isEating) painter->setPen(Qt::red);
    else painter->setPen(Qt::darkGreen);

    this->isEating = false;
    painter->drawRect(this->X, this->Y, 16, 16);

    if(this->nextSnakeBlock != nullptr) { // If this block is not the tail
        this->nextSnakeBlock->draw(painter);
    }
}
