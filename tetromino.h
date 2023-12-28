#ifndef TETROMINO_H
#define TETROMINO_H

#include <QColor>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QObject>
#include <QPainter>
#include <QPixmap>
#include <vector>

#include "utils.h"

class MainWindow;

class Tetromino {
public:
    Tetromino(const TetrominoType &type, MainWindow *w, Coords pos);
    ~Tetromino();

    void render();
    bool moveTo(const Directions &direction);
    bool moveTo(const Coords &c);
    void rotate(const int &direction);
    void rotateIfAble(const int &direction);
    void clear();
    std::vector<Block> blocks() const;
    void setPos(const Coords &pos);

private:
    void move(const Coords &c);
    int SIZE_X = 3;
    int SIZE_Y = 3;
    Coords centerBlockPosition_{1, 1};
    Block centerBlock_ = nullptr;
    RotationState rotation_ = SPAWN;
    Coords pos_;
    MainWindow *w_;
    QPixmap background_;
    TetrominoType type_;
    std::vector<std::vector<int>> shape_;
    std::vector<Block> blocks_;
};

#endif // TETROMINO_H
