#include "snakeblock.h"

SnakeBlock::SnakeBlock(int x, int y, bool isHead)
{
    this->X = x;
    this->Y = y;
    this->isHead = isHead;
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
            this->isEating = false;
        }else{

            this->nextSnakeBlock->updatePosition(oldPosX, oldPosY);
            this->nextSnakeBlock->eatApple();
            this->isEating = false;
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

void SnakeBlock::draw(QPainter * painter, int blockSize)
{
    painter->setRenderHint(QPainter::Antialiasing);
    if(this->isEating) {
        painter->setPen(Qt::red);
        painter->setBrush(Qt::darkGreen);
    }
    else {
        painter->setPen(Qt::black);
        painter->setBrush(Qt::darkGreen);
        if(this->isHead) painter->setBrush(Qt::blue);
    }

    painter->drawRect(this->X, this->Y, blockSize, blockSize);

    if(this->nextSnakeBlock != nullptr) { // If this block is not the tail
        this->nextSnakeBlock->draw(painter, blockSize);
    }
}

bool SnakeBlock::checkCollision(int headX, int headY)
{
    if(this->nextSnakeBlock == nullptr) return false;
    else{
        if(headX == this->X && headY == this->Y) return true;
        else {
            if(!this->isHead) return this->nextSnakeBlock->checkCollision(headX, headY);
            else return this->nextSnakeBlock->checkCollision(this->X, this->Y);
        }
    }
}
