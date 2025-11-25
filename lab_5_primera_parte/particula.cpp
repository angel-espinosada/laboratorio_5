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
    y = y + vy * t;

    tiempo_total += t; // Ahora sí funciona
}

void Particula::ActualizarVelocidad()
{
    vy = vy - g * t;   // aceleración vertical
}

void Particula::moverpaso()
{
    // Guardar valores anteriores para debug
    double x_ant = x;
    double y_ant = y;

    CalcularPosicion();
    ActualizarVelocidad();

    // DEBUG: imprimir cada 50 pasos
    static int contador = 0;
    if (contador++ % 50 == 0) {
        cout << "MOVIMIENTO: (" << x_ant << "," << y_ant << ") -> ("
             << x << "," << y << ") | vx=" << vx << " vy=" << vy << endl;
    }
/*
    // Después verificar colisiones
    chequearPiso(0);
    chequearTecho(5);
    chequearparedIz(0);
    chequearParedDer(10);*/
}

void Particula::chequearTecho(double techo)
{
    if (y +radio>= techo) {
        y = techo-radio;   // Evita que se pase del techo
        vy = -vy;    // Rebote vertical
        cout<<"Toco techo "<<y<<endl;
    }
}

void Particula::chequearparedIz(double parIz)
{
    if (x -radio<= parIz) {
        x = parIz+radio;     // evitar traspaso
        vx = -vx;     // rebote horizontal
        cout << "Toco la PARED IZQUIERDA"<<endl;
    }
}

void Particula::chequearParedDer(double parDer)
{
    if (x+radio >= parDer) {
        x = parDer-radio;    // evitar traspaso
        vx = -vx;    // rebote horizontal
        cout << "Toco la PARED DERECHA"<<endl;
    }
}

void Particula::chequearPiso(double piso)
{
    if (y -radio<= piso) {
        y = piso+radio;        // corregir posicion
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

double Particula::getVx() const
{
    return vx;
}

double Particula::getVy() const
{
    return vy;
}

double Particula::getMasa() const
{
    return masa;
}

double Particula::getRadio() const
{
    return radio;
}

