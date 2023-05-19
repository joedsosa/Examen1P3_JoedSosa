#pragma once
#ifndef NEUMATICOS_H
#define NEUMATICOS_H
class Neumaticos{
public:
	
	Neumaticos(float aceleracion);
	float GetAceleracion();
private:
	float aceleracion;

};
#endif