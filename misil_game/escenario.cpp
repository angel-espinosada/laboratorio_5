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

void Escenario::crearObstaculos()
{
    QGraphicsRectItem *bloque1 = new QGraphicsRectItem(540, 265, 40, 80);
    bloque1->setBrush(QBrush(Qt::green));
    bloque1->setPen(QPen(Qt::darkGreen, 3));
    escena->addItem(bloque1);
    bloques.append(bloque1);
}

void Escenario::crearSuelo()
{
    suelo = new QGraphicsRectItem(0, 350, 799, 50);
    suelo->setBrush(QColor(139, 69, 19));  // café
    suelo->setPen(QPen(Qt::black, 2));
    escena->addItem(suelo);
}
