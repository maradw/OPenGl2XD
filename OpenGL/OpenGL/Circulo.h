#pragma once
#include "Figura2D.h"
class Circulo :
    public Figura2D
{
public:
    int radius;
    void ChangeSize(int size);
};

