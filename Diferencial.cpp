#include "Diferencial.h"
Diferencial::Diferencial(float aceleracion) {
    this->aceleracion = aceleracion;
}

float Diferencial::GetAceleracion() {
    return aceleracion;
}