#include "game.h"

Game::Game(QWidget *parent)
    : QWidget(parent)
{
    std::srand(std::time(nullptr));
    this->head = new SnakeBlock(32, 16, true);
    this->head->nextSnakeBlock = new SnakeBlock(16, 16);

    this->mainTimer = new QTimer();
    this->mainTimer->setInterval(500);

    connect(mainTimer, &QTimer::timeout, this, &Game::updateSnakePosition);
    connect(mainTimer, &QTimer::timeout, this, &Game::drawSnake);

    this->mainTimer->start();

    this->setFixedSize(320, 320);

    this->addApple();
}

Game::~Game()
{

}

void Game::paintEvent(QPaintEvent *)
{
    // Create painter
    QPainter * painter = new QPainter(this);

    // Draw the apple
    painter->setPen(Qt::red);
    painter->drawRect(this->appleX, this->appleY, 16, 16);

    // Draw the snake head
    this->head->draw(painter);

    // Delete painter
    delete painter; painter = nullptr;
}

void Game::updateSnakePosition()
{
    int blockSize = 16;
    if(!(this->X == 0 && this->Y == 0)) {
        int newX = this->head->X + this->X * blockSize;
        int newY = this->head->Y + this->Y * blockSize;

        if(newX < 0) newX =width();
        else if(newX > width()) newX = 0;

        if(newY < 0) newY = height();
        else if(newY > height()) newY = 0;

        if(newX == appleX && newY == appleY) {
            this->head->eatApple();
            this->addApple();
        }

        this->head->updatePosition(newX, newY);
    }
}

void Game::drawSnake()
{
    this->update();
}

void Game::addApple()
{
    int maxX = width() / 16;
    int maxY = height() / 16;
    this->appleX = std::rand()/((RAND_MAX + 1u)/ (maxX));
    this->appleY = std::rand()/((RAND_MAX + 1u)/ (maxY));

    this->appleX *= 16;
    this->appleY *= 16;

    qDebug() << this->appleX << " ; " << this->appleY;
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





