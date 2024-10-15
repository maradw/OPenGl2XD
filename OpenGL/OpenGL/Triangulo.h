#pragma once
#include "Figura2D.h"
class Triangulo :
    public Figura2D
{
public:
    Triangulo();
    int base;
    int height;
    void init() override;
    void ChangeSize(int size);
    void Draw() override;
    void CalculateArea() override;
    void CalculatePerimeter() override;
};

