#pragma once
#ifndef DIFERENCIAL_H
#define DIFERENCIAL_H

class Diferencial {
public:
    Diferencial(float aceleracion);
    float GetAceleracion();

private:
    float aceleracion;
};

#endif

