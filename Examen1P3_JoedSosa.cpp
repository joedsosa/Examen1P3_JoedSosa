
#include <vector>
#include <iostream>
#include <iostream>
#include <vector>
#include "Auto.h"
#include "Ciguenal.h"
#include "Radiador.h"
#include "Neumaticos.h"
#include "Diferencial.h"
#include "CajaDeCambios.h"
using namespace std;
void menu(vector<Auto>& autos) {
    int opcion;
    while(true){
        cout << "Menu: " << endl;
        cout << "1. Agregar Auto " << endl;
        cout << "2. Modificar Auto " << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            string marca, modelo;
            int velmax, hp;
            float acc;

            cout << "Marca: ";
            cin >> marca;
            cout << "Modelo: ";
            cin >> modelo;
            cout << "Velocidad Maxima";
            cin >> velmax;
            cout << "Caballos de Fuerza";
            cin >> hp;
            cout << "Acceleracion: ";
            cin >> acc;
            Auto nuevoAuto(marca, modelo, velmax, hp, acc);
            autos.push_back(nuevoAuto);
            
            cout << " Carro agregado exitosamente" << endl;
            break;

        }
        case 2: {

        }
    }
    }

}
int main(){
    vector<Auto> autos;
    menu(autos);
    return 0;
}

