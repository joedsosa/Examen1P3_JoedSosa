#ifndef AUTO_H
#define AUTO_H

#include <string>
#include <vector>
#include "Ciguenal.h"
#include "Radiador.h"
#include "Neumaticos.h"
#include "Diferencial.h"
#include "CajaDeCambios.h"
using namespace std;

class Auto {
public:
    Auto(std::string marca, string modelo, int velMax, int caballosFuerza, float aceleracion);
    void AgregarComponentes(vector<Ciguenal*>& ciguenales, vector<Radiador*>& radiadores, vector<Neumaticos*>& neumaticos, vector<Diferencial*>& diferenciales, vector<CajaDeCambios*>& cajasCambios);
    void MostrarInfo() const;
    void ModificarComponentes(vector<Ciguenal*>& ciguenales, vector<Radiador*>& radiadores, vector<Neumaticos*>& neumaticos, vector<Diferencial*>& diferenciales, vector<CajaDeCambios*>& cajasCambios);
    static void OrdenarAutos(vector<Auto>& autos, const string& criterio);
    string getMarca() const;
    string getModelo() const;
    int getVelMax() const;
    int getCaballosFuerza()const;
    float getAceleracion() const;
    static void OrdenarAutos(vector<Auto>& autos, const string& criterio);
    float CalcularTiempoAceleracion() const;
    float CalcularDistanciaAceleracion() const;
    float CalcularTiempoVelocidadMaxima(float distancia) const;
    float CalcularTiempoTotal(float distancia) const;
    static std::string DeterminarGanador(const Auto& auto1, const Auto& auto2, float distancia);
    void RealizarCarrea(const Auto& otroAuto, float distancia) const;
    ~Auto();
private:
    string marca;
    string modelo;
    int velMax;
    int caballosFuerza;
    float aceleracion;
    Ciguenal* c;
    Radiador* r;
    Neumaticos* n;
    Diferencial* d;
    CajaDeCambios* cdc;
};

#endif
