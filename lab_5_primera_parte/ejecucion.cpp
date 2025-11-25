#include "ejecucion.h"
#include <iostream>

using namespace std;

Ejecucion::Ejecucion() {}
Ejecucion::Ejecucion(double parIz, double parDer, double piso, double techo){
    this->parIz = parIz;
    this->parDer = parDer;
    this->piso = piso;
    this->techo = techo;
}

void Ejecucion::agregarParticula(const Particula &p)
{
    particulas.push_back(p);
}

void Ejecucion::actualizar()
{
    for (auto& p : particulas)
    {
        p.moverpaso();                  // Se mueve un paso
        p.chequearparedIz(parIz);       // Pared izquierda
        p.chequearParedDer(parDer);       // Pared derecha
        p.chequearPiso(piso);           // Piso
        p.chequearTecho(techo);          // Techo
    }
}

void Ejecucion::mostrarEstado() const
{
    for (size_t i = 0; i < particulas.size(); i++)
    {
        cout<< "P" << i << ": x=" << particulas[i].getX()
        << " y=" << particulas[i].getY() << endl;
    }
}
