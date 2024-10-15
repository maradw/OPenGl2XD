#pragma once
#include "Figura3D.h"
#include "Cuadrado.h"
class Cubo :
    public Figura3D
{
public:
    //Cubo(const std::string& name, int w, float r, float g, float b);
    Cubo();
    void init() override;
    void CalculateVolume() override;  
    void Draw() override;
};

