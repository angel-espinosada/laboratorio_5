#ifndef ARMA_H
#define ARMA_H
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QTimer>


class Arma
{
private:
    QGraphicsScene *escena;
    QGraphicsRectItem *base;      // parte baja del cañón
    QGraphicsRectItem *tubo;      // tubo del cañón

    double anguloActual;
    int posX, posY;
public:
    Arma(QGraphicsScene *escena, int x, int y);
    void setAngulo(double angulo);
    double getAngulo() const { return anguloActual; }
    QPointF getPuntoDeSalida();
    void disparar();


};

#endif // ARMA_H
