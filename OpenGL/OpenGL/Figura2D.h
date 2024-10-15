#pragma once
#include "Figura.h"
class Figura2D : public Figura
{
public: 
	virtual void CalculateArea() = 0;
	virtual void CalculatePerimeter() = 0;
};

