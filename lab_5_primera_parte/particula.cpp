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
