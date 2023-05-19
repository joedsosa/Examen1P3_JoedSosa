#pragma once
#ifndef CAJADECAMBIOS_H
#define CAJADECAMBIOS_H
class CajaDeCambios{
public: 
	CajaDeCambios(float aceleracion, int velmax);
	float GetAceleracion();
	int GetVelMax();
private: 
	float aceleracion;
	int velmax;
};
#endif

