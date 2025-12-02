#include "Arma.h"

Arma::Arma(QGraphicsScene *escena, int x, int y)
{
    anguloActual = -45; // Ángulo inicial
    // La base del cañón
    base = new QGraphicsRectItem(0, y, 40, 20);
    base->setBrush(Qt::darkGray);

    // El ubo del cañón
    tubo = new QGraphicsRectItem(0, y-50, 20, 50);
    tubo->setBrush(Qt::black);
    //tubo->setTransformOriginPoint(0, 0);

    //tubo->setRotation(anguloActual);
    bala = new QGraphicsEllipseItem(0, y-70, 20, 30);
    bala->setBrush(QBrush(Qt::red));
    bala->setPen(QPen(Qt::black, 4));
    escena->addItem(bala);
    escena->addItem(base);
    escena->addItem(tubo);
}

void Arma::setAngulo(double angulo)
{
    // Limitar ángulo entre -90 y 0
    if (angulo < -90) angulo = -90;
    if (angulo > 0) angulo = 0;

    anguloActual = angulo;
    tubo->setRotation(angulo);
}

QPointF Arma::getPuntoDeSalida()
{

    QPointF centro = tubo->sceneBoundingRect().center();
    double largo = 50; // Largo del tubo
    double rad = qDegreesToRadians(anguloActual);

    QPointF punta;
    punta.setX(centro.x() + largo * cos(rad));
    punta.setY(centro.y() + largo * sin(rad));

    return punta;
}

