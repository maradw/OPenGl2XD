#pragma once
#include "Example.h"
#include "Figura.h"
#include "Vector3.h"
#include "TextureLoader.h"
class Example5 : public Example
{
	Figura* cubo;
	Figura* esfera;

	Figura* cuadrado;
	Figura* triangulo;

	//Figura * 
	Vector3 pos;
	TextureLoader* _TextureLoader;
	GLuint texture;

	TextureLoader* _TextureLoader1;
	GLuint texture1;

	TextureLoader* _TextureLoader2;
	GLuint texture2;

	TextureLoader* _TextureLoader3;
	GLuint texture3;
public:
	Example5();
	virtual void init()override;
	virtual void Render()override;
	virtual void KeyboardFunc(unsigned char key, int X, int Y)override;
	virtual void Idle()override;
	void DrawShape();
};

