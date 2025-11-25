#include <iostream>
#include <particula.h>
#include "ejecucion.h"

using namespace std;

int main()
{
    cout<<"hola mundo"<<endl;
    /*
    Particula miParticula;
    miParticula.mensaje();

    Particula mov(0,0,0,0);
    for (int i=0; i<9; i++){
        mov.moverprueba();
        cout<<"X=" <<mov.getX()<< "y"<<mov.getY()<<endl;
    }
    Particula movMRU(0,0,5,0);
    for(int i=0; i<10;i++){
        movMRU.moverMRU();
        cout<< " x MRU=" <<movMRU.getX()<<endl;

    }

    Particula paraboli(0,0,15, 45 * M_PI / 180);
    for(int i= 0; i<300; i++){

        paraboli.moverpaso();
        cout<<"Valor de x "<<paraboli.getX()<<" Valor de y "<<paraboli.getY()<<endl;
    }



*/
    Ejecucion sim(0, 10, 0, 5);  // caja: x=0-10, y=0-5

    // Crear 2 partículas
    Particula p1(0, 0, 15, 45 * M_PI / 180,1,0.8);
    Particula p2(5, 2, 10, 60 * M_PI / 180,2,0.5);

    // Agregarlas al simulador
    sim.agregarParticula(p1);
    sim.agregarParticula(p2);

    // Ejecutar 200 pasos, para que alcance chocar con las paredes
    for (int i = 0; i < 200; i++)
    {
        sim.actualizar();
        sim.mostrarEstado();
        cout << "------------------------" << endl;
    }
    sim.abrirArchivo("datos.txt");
    for (int i = 0; i < 200; i++) {
        sim.actualizar();
        sim.mostrarEstado();
        cout << "------------------------\n";
    }
    sim.cerrarArchivo();

    cin.get();
    return 0;
}
