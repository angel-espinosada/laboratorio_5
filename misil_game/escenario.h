#ifndef ESCENARIO_H
#define ESCENARIO_H

#include<QGraphicsScene>
#include<QGraphicsItem>
#include <QList>

class Escenario
{
    QGraphicsScene *escena;
    QGraphicsRectItem *suelo;
    QList<QGraphicsRectItem*> bloques;

public:
    Escenario(QGraphicsScene *escena);
    Escenario();
    void crearSuelo();
    void crearFondo();
    void crearObstaculos();

};

#endif // ESCENARIO_H
