#include "CajaDeCambios.h"

CajaDeCambios::CajaDeCambios(float aceleracion, int velMax) {
	this->aceleracion = aceleracion;
	this->velmax = velMax;
}
float CajaDeCambios::GetAceleracion() {
	return aceleracion;
}

int CajaDeCambios::GetVelMax() {
	return velmax;
}