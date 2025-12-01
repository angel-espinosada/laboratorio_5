#ifndef ARMA_H
#define ARMA_H
#include <QGraphicsRectItem>
#include <QGraphicsScene>

class Arma
{
public:
    Arma(QGraphicsScene *escena, int x, int y);

private:
    QGraphicsRectItem *base;      // parte baja del cañón
    QGraphicsRectItem *tubo;      // tubo del cañón
};

#endif // ARMA_H
