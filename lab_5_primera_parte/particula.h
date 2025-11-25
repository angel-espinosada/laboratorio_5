#ifndef PARTICULA_H
#define PARTICULA_H
#include <math.h>

class Particula
{
private:
    //Atributos
    double x,y,v,ang,vx,vy;
    double t,g, tiempo_total, masa;
    double radio;

public:
    Particula();
    Particula(double x, double y, double v, double ang,double masa, double radio);
    void mensaje();
    void moverprueba();
    void moverMRU();//De prueba para pasar al movimiento parabolico
    void CalcularVelocidad();
    void CalcularPosicion();
    void ActualizarVelocidad();
    void moverpaso();
    void chequearTecho(double techo);
    void chequearparedIz(double parIz);
    void chequearParedDer(double parDer);
    void chequearPiso(double piso);
    double getX() const;
    double getY() const;
    double getVx() const;
    double getVy() const;
    double getMasa() const;
    double getRadio() const;
};

#endif // PARTICULA_H
