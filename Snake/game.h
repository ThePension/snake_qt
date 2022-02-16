#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QTimer>
#include <QKeyEvent>
#include "snakeblock.h"

class Game : public QWidget
{
    Q_OBJECT

public:
    Game(QWidget *parent = nullptr);
    ~Game();

private slots:
    void updateSnakePosition();
    void drawSnake();
    void addApple();

protected:
    void keyPressEvent(QKeyEvent * e) override;
    void paintEvent(QPaintEvent *) override;

private:
    static const int mapSize = 16;

    //SnakeBlock grid[mapSize][mapSize];

    SnakeBlock * head;

    QTimer * mainTimer;

    int appleX, appleY;

    int X = 1, Y = 0;
};
#endif // GAME_H
