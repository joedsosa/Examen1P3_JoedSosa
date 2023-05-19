#include "Ciguenal.h"

Ciguenal::Ciguenal(int caballosFuerza, int velmax) {
	this->caballosFuerza = caballosFuerza;
	this->velmax = velmax;

}
int Ciguenal::GetCaballosFuerza() {
	return caballosFuerza;
}

int Ciguenal::GetVelMax() {
	return velmax;

}