#pragma once
#ifndef CIGUENAL_H
#define CIGUENAL_H
class Ciguenal{
public:
	int caballosFuerza;
	int velmax;
	int GetCaballosFuerza();
	int GetVelMax();
	
	Ciguenal(int caballosFuerza, int velmax);
};
#endif 

