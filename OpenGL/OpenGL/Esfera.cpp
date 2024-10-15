#include "Esfera.h"
#include "IncludeGL.h"
#include <iostream>
/*Esfera::Esfera(const std::string& name, int w, float r, float g, float b): Figura3D(name, r, g, b)  // Call the constructor of the base class Figura3D
{
    // You can initialize other properties like the width or other specific details of the Esfera.
    this->width = w;  // Assuming width is a member variable of Figura3D or Esfera
}*/
Esfera::Esfera()
{

}
void Esfera::init()
{

}
void Esfera::CalculateVolume() {
    // Assuming the cube's volume is width^3
    float volume = width * width * width;
    //std::cout << "The volume of the cube is: " << volume << std::endl;
}

void Esfera::Draw()
{

	// Crear un objeto de esfera con GLU
	GLUquadricObj* quadric = gluNewQuadric();

	// Configuración de la esfera
	glColor3f(0.0, 0.0, 1.0); // Color azul claro

							  // Dibuja la esfera
	gluSphere(quadric, 0.7, 32, 32); // Radio, slices, stacks

									 // Limpiar el objeto quadric
	gluDeleteQuadric(quadric);
	glFlush();
}