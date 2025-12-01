#include "Arma.h"

Arma::Arma(QGraphicsScene *escena, int x, int y)
{
    // La base del cañón
    base = new QGraphicsRectItem(x, y, 40, 20);
    base->setBrush(Qt::darkGray);

    // El ubo del cañón
    tubo = new QGraphicsRectItem(x + 15, y - 30, 10, 30);
    tubo->setBrush(Qt::black);

    escena->addItem(base);
    escena->addItem(tubo);
}
