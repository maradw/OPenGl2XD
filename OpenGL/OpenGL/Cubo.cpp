#include "Cubo.h"
#include "IncludeGL.h"
#include <iostream>
/*Cubo::Cubo(const std::string& name, int w, float r, float g, float b): Figura3D(name, r, g, b)  // Call the constructor of the base class Figura3D
{
    // You can initialize other properties like the width or other specific details of the cubo.
    this->width = w;  // Assuming width is a member variable of Figura3D or Cubo
}*/
Cubo::Cubo() 
{

}
void Cubo::init()
{

}
void Cubo::CalculateVolume() {
    // Assuming the cube's volume is width^3
    float volume = width * width * width;
    //std::cout << "The volume of the cube is: " << volume << std::endl;
}

void Cubo::Draw() 
{
	glLineWidth(8.0);
	//glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_QUADS);  // Usamos quads para dibujar el cubo

						// Cara frontal (Z positiva)
	glColor3f(1.0, 0.0, 0.0);  // Rojo
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);

	// Cara trasera (Z negativa)
	glColor3f(0.0, 1.0, 0.0);  // Verde
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(0.5, -0.5, -0.5);

	// Cara izquierda (X negativa)
	glColor3f(0.0, 0.0, 1.0);  // Azul
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, -0.5);

	// Cara derecha (X positiva)
	glColor3f(1.0, 1.0, 0.0);  // Amarillo
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, -0.5, 0.5);

	// Cara superior (Y positiva)
	glColor3f(1.0, 0.0, 1.0);  // Magenta
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, 0.5, -0.5);

	// Cara inferior (Y negativa)
	glColor3f(0.0, 1.0, 1.0);  // Cian
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);

	glEnd();
	glFlush();
}