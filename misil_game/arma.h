#ifndef ARMA_H
#define ARMA_H
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>


class Arma
{
public:
    Arma(QGraphicsScene *escena, int x, int y);
    void setAngulo(double angulo);
    double getAngulo() const { return anguloActual; }
    QPointF getPuntoDeSalida();
private:
    QGraphicsRectItem *base;      // parte baja del cañón
    QGraphicsRectItem *tubo;      // tubo del cañón
     QGraphicsEllipseItem *bala;
    double anguloActual;

};

#endif // ARMA_H
