#include <iostream>
#include <particula.h>

using namespace std;

int main()
{
    cout<<"hola mundo"<<endl;
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

    cin.get();
    return 0;
}
