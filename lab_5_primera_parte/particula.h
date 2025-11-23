#ifndef PARTICULA_H
#define PARTICULA_H

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
};

#endif // PARTICULA_H
