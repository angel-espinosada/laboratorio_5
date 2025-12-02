#include "escenario.h"

Escenario::Escenario(QGraphicsScene *scene)
{
    escena = scene;
    crearFondo();
    crearSuelo();
}

void Escenario::crearFondo()
{
    escena->setBackgroundBrush(QColor(135, 206, 235)); // celeste
}

void Escenario::crearSuelo()
{
    suelo = new QGraphicsRectItem(0, 350, 799, 50);
    suelo->setBrush(QColor(139, 69, 19));  // café
    suelo->setPen(QPen(Qt::black, 2));

    escena->addItem(suelo);
}
