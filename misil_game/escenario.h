#ifndef ESCENARIO_H
#define ESCENARIO_H

#include<QGraphicsScene>
#include<QGraphicsItem>

class Escenario
{
    QGraphicsScene *escena;
    QGraphicsRectItem *suelo;

public:
    Escenario(QGraphicsScene *escena);
    Escenario();
    void crearSuelo();
    void crearFondo();

};

#endif // ESCENARIO_H
