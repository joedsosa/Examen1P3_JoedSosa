#include "Neumaticos.h"

Neumaticos::Neumaticos(float aceleracion) {
	this->aceleracion = aceleracion;

}
float Neumaticos::GetAceleracion() {
	return aceleracion;
}