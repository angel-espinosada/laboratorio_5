#ifndef EJECUCION_H
#define EJECUCION_H
#include "particula.h"
#include <vector>


class Ejecucion
{
private:
    std::vector<Particula>particulas;
    double parIz, parDer;
    double piso, techo;
public:
    Ejecucion();
    Ejecucion(double parIz, double parDer, double piso, double techo);
    void agregarParticula(const Particula& p);
     void actualizar();
     void mostrarEstado() const;
     void detectarColisionesEntreParticulas();
};

#endif // EJECUCION_H
