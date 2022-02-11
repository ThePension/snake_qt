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

protected:
    void keyPressEvent(QKeyEvent * e) override;

private:
    static const int mapSize = 16;

    //SnakeBlock grid[mapSize][mapSize];

    SnakeBlock * head;

    QTimer * mainTimer;

    int X = 0, Y = 0;
};
#endif // GAME_H
