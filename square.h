#ifndef SQUARE_H
#define SQUARE_H

#include <QColor>
#include <QGraphicsItem>
#include <QObject>
#include <QPainter>
#include <QPen>

#include "utils.h"

class Square : public QGraphicsItem
{
public:
    Square(double x, double y, QPixmap& background);

    QRectF boundingRect() const override;

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
               QWidget* widget) override;

    bool isCollidingWith(Block block, const Directions& direction);
    bool isCollidingWith(Block block);
    void rotate(Block centerBlock, const int& direction);
    void moveToPos(const Coords& c);
    void move(const Coords& moveTo);
    bool isPossibleMove();
    Coords gridPos();
    bool getActive() const;
    void setActive(const bool& value);

private:
    Coords pos_ = {0, 0};
    QPixmap background_;
    bool active = true;
};

#endif // SQUARE_H
