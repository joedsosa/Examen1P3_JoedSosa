#include "Auto.h"
#include <iostream>
#include <vector>
using namespace std;
Auto::Auto(std::string marca, std::string modelo, int velMax, int caballosFuerza, float aceleracion) {
    this->marca = marca;
    this->modelo = modelo;
    this->velMax = velMax;
    this->caballosFuerza = caballosFuerza;
    this->aceleracion = aceleracion;
}

void Auto::AgregarComponentes(std::vector<Ciguenal*>& ciguenales, std::vector<Radiador*>& radiadores, std::vector<Neumaticos*>& neumaticos, std::vector<Diferencial*>& diferenciales, std::vector<CajaDeCambios*>& cajasCambios) {
    for (Ciguenal* ciguenal : ciguenales) {
        this->velMax += ciguenal->GetVelMax();
        this->caballosFuerza += ciguenal->GetCaballosFuerza();
    }

    for (Radiador* radiador : radiadores) {
        this->caballosFuerza += radiador->GetCaballosFuerza();
    }

    for (CajaDeCambios* cajaCambios : cajasCambios) {
        this->velMax += cajaCambios->GetVelMax();
        this->aceleracion -= cajaCambios->GetAceleracion();
    }
}
Auto:: ~Auto() {
    delete c;
    delete r;
    delete n;
    delete d;
    delete cdc;
}

void Auto::MostrarInfo() {
    std::cout << "Marca: " << marca << std::endl;
    std::cout << "Modelo: " << modelo << std::endl;
    std::cout << "Velocidad M�xima: " << velMax << " km/h" << std::endl;
    std::cout << "Caballos de Fuerza: " << caballosFuerza << std::endl;
    std::cout << "Aceleraci�n (0-100 km/h): " << aceleracion << " segundos" << std::endl;
}
void Auto::ModificarComponentes(vector<Ciguenal*>& ciguenales, vector<Radiador*>& radiadores,
    vector<Neumaticos*>& neumaticos, vector<Diferencial*>& diferenciales,
    vector<CajaDeCambios*>& cajasCambios){
    cout << "Componentes disponibles: " << endl;
    cout << "1. Ciguenal" << endl;
    cout << "2. Radiador" << endl;
    cout << "3. Neumaticos" << endl;
    cout << "4. Diferencial" << endl;
    cout << "5. Caja de Cambios" << endl;

    int opcion;
    cout << "Seleccione el numero de componente a modificar";
    cin >> opcion;

    switch (opcion) {
    case 1: {
        int ciguenalIndex;
        std::cout << "Seleccione el n�mero de cig�e�al a utilizar: ";
        std::cin >> ciguenalIndex;
        ciguenalIndex--;
        if (ciguenalIndex >= 0 && ciguenalIndex < ciguenales.size()) {
            Ciguenal* ciguenalSeleccionado = ciguenales[ciguenalIndex];
            velMax += ciguenalSeleccionado->GetVelMax();
            caballosFuerza += ciguenalSeleccionado->GetCaballosFuerza();
        }
        else {
            std::cout << "�ndice de cig�e�al inv�lido." << std::endl;
        }
        break;
    }
    case 2: {
        int radiadorIndex;
        std::cout << "Seleccione el n�mero de radiador a utilizar: ";
        std::cin >> radiadorIndex;
        radiadorIndex--;

        if (radiadorIndex >= 0 && radiadorIndex < radiadores.size()) {
            Radiador* radiadorSeleccionado = radiadores[radiadorIndex];
            caballosFuerza += radiadorSeleccionado->GetCaballosFuerza();
        }
        else {
            std::cout << "�ndice de radiador inv�lido." << std::endl;
        }
        break;
    }
    case 3: {
        int neumaticosIndex;
        std::cout << "Seleccione el n�mero de neum�ticos a utilizar: ";
        std::cin >> neumaticosIndex;
        neumaticosIndex--;

        if (neumaticosIndex >= 0 && neumaticosIndex < neumaticos.size()) {
            Neumaticos* neumaticosSeleccionados = neumaticos[neumaticosIndex];
            aceleracion -= neumaticosSeleccionados->GetAceleracion();
        }
        else {
            std::cout << "�ndice de neum�ticos inv�lido." << std::endl;
        }
        break;
    }case 4: {
        int diferencialIndex;
        cout << "Seleccione el n�mero de diferencial a utilizar: ";
        cin >> diferencialIndex;
        diferencialIndex--;

        if (diferencialIndex >= 0 && diferencialIndex < diferenciales.size()) {
            Diferencial* diferencialSeleccionado = diferenciales[diferencialIndex];
            aceleracion -= diferencialSeleccionado->GetAceleracion();
        }
        else {
            cout << "�ndice de diferencial inv�lido." << std::endl;
        }
        break;
    }
    case 5: {
        int cajaCambiosIndex;
        cout << "Seleccione el n�mero de caja de cambios a utilizar: ";
        cin >> cajaCambiosIndex;
        cajaCambiosIndex--;

        if (cajaCambiosIndex >= 0 && cajaCambiosIndex < cajasCambios.size()) {
            CajaDeCambios* cajaCambiosSeleccionada = cajasCambios[cajaCambiosIndex];
            velMax += cajaCambiosSeleccionada->GetVelMax();
            aceleracion -= cajaCambiosSeleccionada->GetAceleracion();
        }
        else {
            cout << "�ndice de caja de cambios inv�lido"; 
        }
         cout <<endl;

          break;
    }
        default:
            cout << "Opci�n inv�lida." << endl;
            break;
}


}
