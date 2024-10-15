#include "Example.h"
#include <GL/glut.h>
#include <stdio.h>

Example::Example()
{
}

void Example::DrawAxis(GLfloat distance, GLfloat axisWidth)
{
	glLineWidth(axisWidth);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBegin(GL_LINES);
	// Eje X
	// Parte positiva (color rojo)
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);   
	glVertex3f(distance, 0.0f, 0.0f); 
	// Parte negativa (color cian)
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);   
	glVertex3f(-distance, 0.0f, 0.0f);
	// Eje Y
	// Parte positiva (color verde)
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);   
	glVertex3f(0.0f, distance, 0.0f);
	// Parte negativa (color morado)
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);  
	glVertex3f(0.0f, -distance, 0.0f);
	// Eje Z
	// Parte positiva (color azul)
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);  
	glVertex3f(0.0f, 0.0f, distance); 
	// Parte negativa (color amarillo)
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);   
	glVertex3f(0.0f, 0.0f, -distance);

	glEnd();
	glFlush;
}

void Example::DrawGrids(GLfloat LineWidth)
{
	//std::cout << "DrawGrid" << std::endl;
	glLineWidth(LineWidth);
	glColor3f(5.0f, 2.0f, 4.0f);
	glBegin(GL_LINES);

	//Dibujar líneas en el plano XZ
	for (float z = -10.0f; z <= 10.0f; z += 1.0f) {
		glVertex3f(-10.0f, 0.0f, z);
		glVertex3f(10.0f, 0.0f, z);
	}
	// Dibujar líneas en el plano XZ (paralelas al eje Z)
	for (float x = -10.0f; x <= 10.0f; x += 1.0f) {
		glVertex3f(x, 0.0f, -10.0f);
		glVertex3f(x, 0.0f, 10.0f);
	}

	glEnd();
	glFlush;
	glutSwapBuffers();

}

