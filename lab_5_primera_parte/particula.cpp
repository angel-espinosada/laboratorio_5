#include "particula.h"
#include <iostream>
using namespace std;
Particula::Particula() {}
Particula::Particula(double x, double y, double v, double ang)
{
    this->x=x;
    this->y=y;
    this->v=v;
    this->ang=ang;
    t=0.01;
    g=9.8;
    tiempo_total=0;
    CalcularVelocidad();
}

void Particula::mensaje()
{
    cout<<"Particula, objeto"<<endl;
}

void Particula::moverprueba()
{
    x +=1;
    y +=1;
}

void Particula::moverMRU()
{
    x = x + v * t;
}

void Particula::CalcularVelocidad()
{
    //velocidad incial
    vx = v * cos(ang);
    vy = v * sin(ang);
}

void Particula::CalcularPosicion()
{
    x = x + vx * t;
    y = y + vy * t - 0.5 * g * t * t;

    tiempo_total += t; // Ahora sí funciona
}

void Particula::ActualizarVelocidad()
{
    vy = vy - g * t;   // aceleración vertical
}

void Particula::moverpaso()
{
    CalcularPosicion();      // mueve x,y
    ActualizarVelocidad();   // modifica vy para el siguiente paso
}

double Particula::getX() const
{
    return x;
}

double Particula::getY() const
{
    return y;
}
