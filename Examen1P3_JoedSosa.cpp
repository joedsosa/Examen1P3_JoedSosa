
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
#include <algorithm>
using namespace std;

int main(){
    vector<Ciguenal*> ciguenales;
    vector<Radiador*> radiadores;
    vector<Neumaticos*> neumaticos;
    vector<Diferencial*> diferenciales;
    vector<CajaDeCambios*> cajasCambios;
    vector<Auto> autos;
    
    ciguenales.push_back(new Ciguenal(100, 200));
    ciguenales.push_back(new Ciguenal(170, 300));
    ciguenales.push_back(new Ciguenal(180, 400));

    radiadores.push_back(new Radiador(50));
    radiadores.push_back(new Radiador(100));
    radiadores.push_back(new Radiador(150));

    diferenciales.push_back(new Diferencial(7.6));
    diferenciales.push_back(new Diferencial(8.9));
    diferenciales.push_back(new Diferencial(12.4));

    cajasCambios.push_back(new CajaDeCambios(6.8, 300));
    cajasCambios.push_back(new CajaDeCambios(8.8, 200));
    cajasCambios.push_back(new CajaDeCambios(14.9, 500));

    char opcion;
    do {
        cout << "Menu: " << endl;
        cout << "1. Agregar auto: " << endl;
        cout << "2. Modificar auto " << endl;
        cout << "3. Ordenar Autos " << endl;
        cout << "4. Carrera" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opcion: " << endl;
        cin >> opcion;

        switch (opcion) {
        case '1': {
            string marca, modelo;
            int velMax, caballosFuerza;
            float aceleracion;

            cout << "Marca: ";
            cin >> marca;
            cout << "Modelo: ";
            cin >> modelo;
            cout << "Velocidad Maxima: ";
            cin >> velMax;
            cout << "Caballos de Fuerza: ";
            cin >> caballosFuerza;
            cout << "Aceleracion: ";
            cin >> aceleracion;

            Auto nuevoAuto(marca, modelo, velMax, caballosFuerza, aceleracion);
            autos.push_back(nuevoAuto);
            break;
        }
        case '2': {
            cout << "Autos existentes: " << endl;
            for (size_t i = 0; i < autos.size(); i++){
                cout << i + 1 << ". ";
                autos[i].MostrarInfo();
                cout << endl;
            }
            int autoIndex;
            cout << "Seleccione el numero a modificar: ";
            cin >> autoIndex;
            autoIndex--;
            if (autoIndex >= 0 && autoIndex < autos.size()) {
                Auto& autoModificar = autos[autoIndex];
                autoModificar.ModificarComponentes(ciguenales, radiadores, neumaticos, diferenciales, cajasCambios);
                std::cout << "Auto modificado correctamente." << std::endl;
            }
            else {
                std::cout << "Número de auto inválido." << std::endl;
            }

            break;
        
        }
        case '3': {
            char orden;
            cout << "Seleccione el criterio para ordenarlos: " << endl;
            cout << "1. Velocidad Maxima" << endl;
            cout << "2. Caballos de Fuerza" << endl;
            cout << "3. Aceleracion " << endl;
            cout << "Ingrese la opcion ";
            cin >> orden;
            switch (orden) {
            case '1': 
                sort(autos.begin(), autos.end(), [](const Auto& a, const Auto& b) {
                    return a.getVelMax() > b.getVelMax();
                    });
                break;
            case '2':
                std::sort(autos.begin(), autos.end(), [](const Auto& a, const Auto& b) {
                    return a.getCaballosFuerza() > b.getCaballosFuerza();
                    });
                break;
            case '3':
                std::sort(autos.begin(), autos.end(), [](const Auto& a, const Auto& b) {
                    return a.getAceleracion() < b.getAceleracion();
                    });
                break;
            default:
                std::cout << "Opción inválida." << std::endl;
                break;
            }
            cout << "Ordenado: " << endl;
            for (const Auto& autoObj : autos) {
                autoObj.MostrarInfo();
                cout << endl;
            }
            

            break;
        }
        case '4': {
            cout << "Lista de autos";
            for (size_t i = 0; i < autos.size(); i++) {
                cout << i + 1 << ". ";
                autos[i].MostrarInfo();
                cout << endl;
            }
            int autoIndex1, autoIndex2;
            float distancia;

            cout << "Seleccione el numero del primer auto: ";
            cin >> autoIndex1;
            autoIndex1--;
            cout << "Seleccione el numero del segundo auto: ";
            cin >> autoIndex2;
            autoIndex2--;
            cout << "Ingrese la distancia de la carrea en kn: ";
            cin >> distancia;

            if (autoIndex1 >= 0 && autoIndex1 < autos.size() && autoIndex2 >= 0 && autoIndex2 < autos.size()) {
                const Auto& auto1 = autos[autoIndex1];
                const Auto& auto2 = autos[autoIndex2];
                auto1.RealizarCarrea(auto2, distancia);
            }
            else {
                cout << "Indices no validos" << endl;
            }
            break;
        }
        case '5':
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opcion invalida" << endl;
            break;
    }
        cout << endl;

    } while (opcion != '5');
    for (Ciguenal* ciguenal : ciguenales) {
        delete ciguenal;
    }
    for (Radiador* radiador : radiadores) {
        delete radiador;
    }
    for (Neumaticos* neumatico : neumaticos) {
        delete neumatico;
    }
    for (Diferencial* diferencial : diferenciales) {
        delete diferencial;
    }
    for (CajaDeCambios* cajaCambios : cajasCambios) {
        delete cajaCambios;
    }

}

