#pragma once
#include "Example.h"
#include "Figura.h"
class Example6 : public Example
{
	Figura* cubo;
	Figura* esfera;
	Figura* cuadrado;
public: 
	Example6();

	
	int sphereList;
	int cubeList;
	int quadList;
	virtual void init()override;
	virtual void Render()override;
	virtual void KeyboardFunc(unsigned char key, int X, int Y)override;
	virtual void Idle()override;
	void CreateCubeDisplayList();
	void CreateSphereDisplayList();
	void CreateQuadDisplayList();
};

