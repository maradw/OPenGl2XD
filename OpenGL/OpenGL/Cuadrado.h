#pragma once
#include "Figura2D.h"
class Cuadrado : public Figura2D
{
public: 
    Cuadrado();
    int side;
    void init() override;
    void ChangeSize(int size);
    void Draw() override;
    void CalculateArea() override;
    void CalculatePerimeter() override;
};

