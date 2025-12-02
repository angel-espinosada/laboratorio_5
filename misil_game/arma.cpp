#include "Arma.h"

Arma::Arma(QGraphicsScene *escena, int x, int y): escena(escena), anguloActual(-45), posX(x), posY(y)
{

    // La base del cañón
    base = new QGraphicsRectItem(0, y, 40, 20);
    base->setBrush(Qt::darkGray);

    // El ubo del cañón
    tubo = new QGraphicsRectItem(0, y-50, 20, 50);
    tubo->setBrush(Qt::black);
    //tubo->setTransformOriginPoint(0, 0);

    //tubo->setRotation(anguloActual);

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


    double largo = 50; // Largo del tubo
    double rad = qDegreesToRadians(anguloActual);

    double px = posX + largo * cos(rad);
    double py = posY - largo * sin(rad); // ¡restamos porque Y crece hacia abajo!

    return QPointF(px, py);
}

void Arma::disparar()
{
   QGraphicsEllipseItem *bala = new QGraphicsEllipseItem(-3, -3, 6, 6);
    bala->setBrush(QBrush(Qt::red));
    bala->setPen(QPen(Qt::black, 4));
    bala->setPos(getPuntoDeSalida());
    escena->addItem(bala);

    double rad = qDegreesToRadians(anguloActual);
    double v = 8.0;
    double vx = v * cos(rad);
    double vy = -v * sin(rad); // Y crece hacia abajo

    // Mover con timer
    QTimer *timer = new QTimer();
    timer->start(30);
    connect(timer, &QTimer::timeout, [=]() {
        bala->setPos(bala->x() + vx, bala->y() + vy);

        // Eliminar si toca el suelo o sale de la pantalla
        if (bala->y() > 350 || bala->x() < 0 || bala->x() > 800) {
            escena->removeItem(bala);
            delete bala;
            timer->stop();
            timer->deleteLater();
        }
    });
}

