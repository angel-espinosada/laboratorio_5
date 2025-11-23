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
    vx=v*cos(ang);
    vy=v*sin(ang)-g*t;
}

double Particula::getX() const
{
    return x;
}

double Particula::getY() const
{
    return y;
}
