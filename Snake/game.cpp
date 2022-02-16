#include "game.h"

Game::Game(QWidget *parent) : QWidget(parent)
{
    std::srand(std::time(nullptr));
    this->head = new SnakeBlock(10 * blockSize, 10 * blockSize, true);

    this->mainTimer = new QTimer();
    this->mainTimer->setInterval(300);


    connect(mainTimer, &QTimer::timeout, this, &Game::updateSnakePosition);
    connect(mainTimer, &QTimer::timeout, this, &Game::drawSnake);
    connect(mainTimer, &QTimer::timeout, this, &Game::checkCollision);

    this->mainTimer->start();

    this->setFixedSize(20 * blockSize, 20 * blockSize);

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
    painter->drawRect(this->appleX, this->appleY, blockSize, blockSize);

    // Draw the snake head
    this->head->draw(painter, blockSize);

    // Delete painter
    delete painter; painter = nullptr;
}

void Game::updateSnakePosition()
{
    if(!(this->X == 0 && this->Y == 0)) {
        int newX = this->head->X + this->X * blockSize;
        int newY = this->head->Y + this->Y * blockSize;

        if(newX < 0) newX =width() - blockSize;
        else if(newX > width() - blockSize) newX = 0;

        if(newY < 0) newY = height() - blockSize;
        else if(newY > height() - blockSize) newY = 0;

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
    int maxX = width() / blockSize;
    int maxY = height() / blockSize;
    this->appleX = std::rand()/((RAND_MAX + 1u)/ (maxX));
    this->appleY = std::rand()/((RAND_MAX + 1u)/ (maxY));

    this->appleX *= blockSize;
    this->appleY *= blockSize;
}

void Game::checkCollision()
{
    if(this->head->checkCollision(-1, -1)){
        this->mainTimer->stop();
        qDebug() << "Game over";
    }
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





