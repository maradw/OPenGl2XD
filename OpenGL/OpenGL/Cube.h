#pragma once
#include "Polígono.h"
class Cube :  public Polígono
{
private:
	Vector3 position;
public:
	virtual void init() = 0;
	virtual void Render() = 0;
	virtual void KeyboardFunc(unsigned char key, int X, int Y) = 0;
	virtual void Idle() = 0;

	//

	void MoveForward();   // Método para mover el cubo hacia adelante
    void MoveBackward();  // Método para mover el cubo hacia atrás
    void StrafeLeft();    // Método para mover el cubo a la izquierda
    void StrafeRight();   // Método para mover el cubo a la derecha
	void DrawCube1();
};

