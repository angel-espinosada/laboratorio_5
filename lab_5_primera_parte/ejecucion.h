#ifndef EJECUCION_H
#define EJECUCION_H
#include "particula.h"
#include <vector>
#include <fstream>

using namespace std;
class Ejecucion
{
private:
    vector<Particula>particulas;
    double parIz, parDer;
    double piso, techo;
    ofstream archivo;

public:
    Ejecucion();
    Ejecucion(double parIz, double parDer, double piso, double techo);
    void agregarParticula(const Particula& p);
     void actualizar();
     void mostrarEstado() const;
     void detectarColisionesEntreParticulas();
     void abrirArchivo(const string& nombre);
     void cerrarArchivo();
};

#endif // EJECUCION_H
