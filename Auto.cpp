#include "Auto.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
Auto::Auto(std::string marca, std::string modelo, int velMax, int caballosFuerza, float aceleracion) {
    this->marca = marca;
    this->modelo = modelo;
    this->velMax = velMax;
    this->caballosFuerza = caballosFuerza;
    this->aceleracion = aceleracion;
}

void Auto::AgregarComponentes(vector<Ciguenal*>& ciguenales, vector<Radiador*>& radiadores, vector<Neumaticos*>& neumaticos, vector<Diferencial*>& diferenciales, vector<CajaDeCambios*>& cajasCambios) {
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

string Auto::getMarca() const {
    return marca;
}

string Auto::getModelo() const {
    return modelo;
}

int Auto::getVelMax() const {
    return velMax;
}

int Auto::getCaballosFuerza() const {
    return caballosFuerza;
}

float Auto::getAceleracion() const {
    return aceleracion;
}

void Auto::MostrarInfo() const {
    cout << "Marca: " << marca << endl;
    cout << "Modelo: " << modelo << endl;
    cout << "Velocidad Máxima: " << velMax << " km/h" << endl;
    cout << "Caballos de Fuerza: " << caballosFuerza << endl;
    cout << "Aceleración (0-100 km/h): " << aceleracion << " segundos" << endl;
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
        cout << "Seleccione el número de cigüeñal a utilizar: ";
        cin >> ciguenalIndex;
        ciguenalIndex--;
        if (ciguenalIndex >= 0 && ciguenalIndex < ciguenales.size()) {
            Ciguenal* ciguenalSeleccionado = ciguenales[ciguenalIndex];
            velMax += ciguenalSeleccionado->GetVelMax();
            caballosFuerza += ciguenalSeleccionado->GetCaballosFuerza();
        }
        else {
            cout << "Índice de cigüeñal inválido." << endl;
        }
        break;
    }
    case 2: {
        int radiadorIndex;
        cout << "Seleccione el número de radiador a utilizar: ";
        cin >> radiadorIndex;
        radiadorIndex--;

        if (radiadorIndex >= 0 && radiadorIndex < radiadores.size()) {
            Radiador* radiadorSeleccionado = radiadores[radiadorIndex];
            caballosFuerza += radiadorSeleccionado->GetCaballosFuerza();
        }
        else {
            cout << "Índice de radiador inválido." << endl;
        }
        break;
    }
    case 3: {
        int neumaticosIndex;
        cout << "Seleccione el número de neumáticos a utilizar: ";
        cin >> neumaticosIndex;
        neumaticosIndex--;

        if (neumaticosIndex >= 0 && neumaticosIndex < neumaticos.size()) {
            Neumaticos* neumaticosSeleccionados = neumaticos[neumaticosIndex];
            aceleracion -= neumaticosSeleccionados->GetAceleracion();
        }
        else {
            cout << "Índice de neumáticos inválido." << endl;
        }
        break;
    }case 4: {
        int diferencialIndex;
        cout << "Seleccione el número de diferencial a utilizar: ";
        cin >> diferencialIndex;
        diferencialIndex--;

        if (diferencialIndex >= 0 && diferencialIndex < diferenciales.size()) {
            Diferencial* diferencialSeleccionado = diferenciales[diferencialIndex];
            aceleracion -= diferencialSeleccionado->GetAceleracion();
        }
        else {
            cout << "Índice de diferencial inválido." << endl;
        }
        break;
    }
    case 5: {
        int cajaCambiosIndex;
        cout << "Seleccione el número de caja de cambios a utilizar: ";
        cin >> cajaCambiosIndex;
        cajaCambiosIndex--;

        if (cajaCambiosIndex >= 0 && cajaCambiosIndex < cajasCambios.size()) {
            CajaDeCambios* cajaCambiosSeleccionada = cajasCambios[cajaCambiosIndex];
            velMax += cajaCambiosSeleccionada->GetVelMax();
            aceleracion -= cajaCambiosSeleccionada->GetAceleracion();
        }
        else {
            cout << "Índice de caja de cambios inválido"; 
        }
         cout <<endl;

          break;
    }
        default:
            cout << "Opción inválida." << endl;
            break;
}


}
void Auto::OrdenarAutos(vector<Auto>& autos, const string& criterio) {
        sort(autos.begin(), autos.end(), [&criterio](const Auto& a, const Auto& b) {
        if (criterio == "velocidad") {
            return a.velMax > b.velMax;
        }
        else if (criterio == "caballos") {
            return a.caballosFuerza > b.caballosFuerza;
        }
        else if (criterio == "aceleracion") {
            return a.aceleracion < b.aceleracion;
        }
        else {
            return false;
        }
        });
}
float Auto::CalcularTiempoAceleracion() const {
    return (velMax) / aceleracion;
}

float Auto::CalcularDistanciaAceleracion() const {
    float ta = CalcularTiempoAceleracion();
    return 0.5f * aceleracion * ta * ta;
}

float Auto::CalcularTiempoVelocidadMaxima(float distancia) const {
    float da = CalcularDistanciaAceleracion();
    return (da - distancia) / velMax;
}

float Auto::CalcularTiempoTotal(float distancia) const {
    return CalcularTiempoAceleracion();
        CalcularTiempoVelocidadMaxima(distancia);
        
}
string Auto::DeterminarGanador(const Auto& auto1, const Auto& auto2, float distancia) {
    float tiempoAuto1 = auto1.CalcularTiempoTotal(distancia);
    float tiempoAuto2 = auto2.CalcularTiempoTotal(distancia);
    if (tiempoAuto1 < tiempoAuto2) {
        return auto1.marca + " " + auto1.modelo;
    }
    else if (tiempoAuto2 < tiempoAuto1) {
        return auto2.marca + " " + auto2.modelo;
    }
    else {
        return "Empate";
    }
    }
    void Auto::RealizarCarrea(const Auto& otroAuto, float distancia) const {
        cout << "Comienza la carrera!" << endl;

        float tiempoAuto1 = aceleracion * distancia;
        float tiempoAuto2 = otroAuto.aceleracion * distancia;

        if (tiempoAuto1 < tiempoAuto2) {
            cout << "¡Gana el Auto 1!" << endl;
        }
        else if (tiempoAuto2 < tiempoAuto1) {
            cout << "¡Gana el Auto 2!" << endl;
        }
        else {
            cout << "¡Es un empate!" << endl;
        }
    }
