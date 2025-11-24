#ifndef PARTICULA_H
#define PARTICULA_H
#include <math.h>

class Particula
{
private:
    //Atributos
    double x,y,v,ang,vx,vy;
    double t,g;

public:
    Particula();
    Particula(double x, double y, double v, double ang);
    void mensaje();
    void moverprueba();
    void moverMRU();//De prueba para pasar al movimiento parabolico
    void CalcularVelocidad();
    void CalcularPosicion();
    void ActualizarVelocidad();
    double getX() const;
    double getY() const;
};

#endif // PARTICULA_H
