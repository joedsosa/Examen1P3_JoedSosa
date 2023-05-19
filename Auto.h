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
    void MostrarInfo();

private:
    std::string marca;
    std::string modelo;
    int velMax;
    int caballosFuerza;
    float aceleracion;
};

#endif
