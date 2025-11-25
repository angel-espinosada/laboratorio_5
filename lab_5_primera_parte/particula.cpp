#include "particula.h"
#include <iostream>
using namespace std;
Particula::Particula() {}
Particula::Particula(double x, double y, double v, double ang, double masa, double radio)
{
    this->x=x;
    this->y=y;
    this->v=v;
    this->ang=ang;
    this->masa = masa;
    this->radio = radio;
    t=0.01;
    g=9.8;
    tiempo_total=0;
    vx = v * cos(ang);
    vy = v * sin(ang);
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
    ActualizarVelocidad();   // gravedad primero
    CalcularPosicion();      // mover la partícula

    // Después verificar colisiones
    chequearPiso(0);
    chequearTecho(5);
    chequearparedIz(0);
    chequearParedDer(10);
}

void Particula::chequearTecho(double techo)
{
    if (y >= techo) {
        y = techo;   // Evita que se pase del techo
        vy = -vy;    // Rebote vertical
        cout<<"Toco techo "<<y<<endl;
    }
}

void Particula::chequearparedIz(double parIz)
{
    if (x <= parIz) {
        x = parIz;     // evitar traspaso
        vx = -vx;     // rebote horizontal
        cout << "Toco la PARED IZQUIERDA"<<endl;
    }
}

void Particula::chequearParedDer(double parDer)
{
    if (x >= parDer) {
        x = parDer;    // evitar traspaso
        vx = -vx;    // rebote horizontal
        cout << "Toco la PARED DERECHA"<<endl;
    }
}

void Particula::chequearPiso(double piso)
{
    if (y <= piso) {
        y = piso;        // corregir posicion
        vy = -vy;     // invertir velocidad vertical
        cout<<"Toco piso "<<y<<endl;
}
}

double Particula::getX() const
{
    return x;
}

double Particula::getY() const
{
    return y;
}
