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
     detectarColisionesEntreParticulas();
}

void Ejecucion::mostrarEstado() const
{
    for (size_t i = 0; i < particulas.size(); i++)
    {
        cout<< "P" << i << ": x=" << particulas[i].getX()
        << " y=" << particulas[i].getY() << endl;
    }
}

void Ejecucion::detectarColisionesEntreParticulas()
{
    for (size_t i = 0; i < particulas.size(); i++)
    {
        for (size_t j = i + 1; j < particulas.size(); j++)
        {
            double dx = particulas[j].getX() - particulas[i].getX();
            double dy = particulas[j].getY() - particulas[i].getY();
            double dist = sqrt(dx * dx + dy * dy);

            double sumaRadios =
                particulas[i].getRadio() + particulas[j].getRadio();

            if (dist <= sumaRadios)
            {
                cout << "COLISION entre P" << i
                     << " y P" << j << endl;
            }
        }
    }
}

void Ejecucion::abrirArchivo(const string &nombre)
{
    archivo.open(nombre);
    if (!archivo.is_open()) {
        cout << "Error al abrir archivo\n";
    }
    else{
        cout<<"Abierto corectamente"<<endl;
    }
}

void Ejecucion::cerrarArchivo()
{
    if (archivo.is_open()) {
        archivo.close();
    }
}
