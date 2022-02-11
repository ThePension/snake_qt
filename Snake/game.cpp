#include "game.h"

Game::Game(QWidget *parent)
    : QWidget(parent)
{
    this->head = new SnakeBlock(5, 5);

    this->mainTimer = new QTimer();
    this->mainTimer->setInterval(500);

    connect(mainTimer, &QTimer::timeout, this, &Game::updateSnakePosition);

    this->mainTimer->start();
}

Game::~Game()
{

}

void Game::updateSnakePosition()
{
    this->head->updatePosition(this->X, this->Y);
}

void Game::keyPressEvent(QKeyEvent *ke)
{
    switch(ke->key()) {
        case Qt::Key_W:
            this->X = 0;
            this->Y = -1;
            break;
        case Qt::Key_S:
            this->X = 0;
            this->Y = 1;
            break;
        case Qt::Key_D:
            this->X = 1;
            this->Y = 0;
            break;
        case Qt::Key_A:
            this->X = -1;
            this->Y = 0;
            break;
    }
}



