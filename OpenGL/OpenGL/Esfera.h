#pragma once
#include "Figura3D.h"
class Esfera :
    public Figura3D
{
public:
    int radius;
    Esfera();
   // Esfera(const std::string& name, int w, float r, float g, float b);
    void CalculateVolume() override;  // Sobrescribe el cálculo de volumen
    void init() override;
    void Draw() override;
};

