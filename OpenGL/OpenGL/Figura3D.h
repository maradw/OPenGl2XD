#pragma once
#include "Figura.h"
class Figura3D : public Figura
{
public:
	//Figura3D(const std::string& name, float r, float g, float b);
	Figura3D();
	virtual void CalculateVolume();
	void init() = 0;

};

