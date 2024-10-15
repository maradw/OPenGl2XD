#include "Polígono.h"
#include "IncludeGL.h"
#include <iostream>

Vector3 position;
Polígono::Polígono(): position(0.0f, 0.0f, 0.0f)
{
   
}
/*Polígono::Polígono() : position(0.0f, 0.0f, 0.0f) // Posición inicial
{
}
*/
void Polígono::init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0);
   
    gluLookAt(5, 5, 5, 0, 0, 0, 0, 1, 0);
    glMatrixMode(GL_MODELVIEW);
}
void Polígono::Render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   
    glutSwapBuffers();
    //glFlush();

}

void Polígono::KeyboardFunc(unsigned char key, int x, int y)
{
   
}
void Polígono::DrawCube(int a, int b, int c)
{
	glLineWidth(8.0);
	glPushMatrix();
	glTranslatef(a,b,c);
	 // Evita afectar otras partes de la escena
	
	//glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_QUADS);

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
	glPopMatrix();
	glEnd();
	glFlush();
}
void Polígono::DrawSphere(int x, int y, int z)
{
	GLUquadricObj* quadric = gluNewQuadric();
	glScalef(1.0f, 1.0f, 1.0f);
	glTranslatef(x, y, z);
	glColor3f(0.0, 0.5, 1.0); // Color azul claro

	gluSphere(quadric, 1.0, 32, 32); // Radio, slices, stacks
	gluDeleteQuadric(quadric);
	glFlush();
}
void Polígono::Idle()
{

}
void Polígono::DrawCone(int x, int y, int z)
{
	// Crear un objeto de cilindro con GLU
	GLUquadricObj* quadric = gluNewQuadric();
	glScalef(1.5f, 1.5f, 1.5f);
	glTranslatef(x, y, z);
	// Configuración del cono
	glColor3f(0.0f, 1.0f, 1.0f);



							  // Dibujar el cono
	gluCylinder(quadric, 1.0, 0.0, 2.0, 32, 32); // Radio superior, radio inferior (0 para cono), altura, slices, stacks

												 // Limpiar el objeto quadric
	gluDeleteQuadric(quadric);
	glFlush();
}
void Polígono::DrawOrthohedron(int x, int y, int z)
{
	glColor3f(0.5, 0.2, 0.8); // Morado
	glTranslatef(x, y, z);
	glBegin(GL_POLYGON);
	glVertex3f(-1.0, 1.0, -0.5);
	glVertex3f(1.5, 1.0, -0.5);
	glVertex3f(1.5, 1.0, 0.5);
	glVertex3f(-1.0, 1.0, 0.5);
	glEnd();

	// Base inferior (rectángulo)
	glColor3f(0.2, 0.8, 0.5); // Verde claro
	glBegin(GL_POLYGON);
	glVertex3f(-1.0, -1.0, -0.5);
	glVertex3f(1.5, -1.0, -0.5);
	glVertex3f(1.5, -1.0, 0.5);
	glVertex3f(-1.0, -1.0, 0.5);
	glEnd();

	// Cara frontal
	glColor3f(1.0, 0.5, 0.0); // Naranja
	glBegin(GL_POLYGON);
	glVertex3f(-1.0, 1.0, -0.5); // Vértice superior izquierdo
	glVertex3f(1.5, 1.0, -0.5); // Vértice superior derecho
	glVertex3f(1.5, -1.0, -0.5); // Vértice inferior derecho
	glVertex3f(-1.0, -1.0, -0.5); // Vértice inferior izquierdo
	glEnd();

	// Cara derecha
	glColor3f(0.0, 0.7, 1.0); // Azul celeste
	glBegin(GL_POLYGON);
	glVertex3f(1.5, 1.0, -0.5); // Vértice superior izquierdo
	glVertex3f(1.5, 1.0, 0.5); // Vértice superior derecho
	glVertex3f(1.5, -1.0, 0.5); // Vértice inferior derecho
	glVertex3f(1.5, -1.0, -0.5); // Vértice inferior izquierdo
	glEnd();

	// Cara trasera
	glColor3f(1.0, 0.0, 0.0); // Rojo
	glBegin(GL_POLYGON);
	glVertex3f(1.5, 1.0, 0.5); // Vértice superior derecho
	glVertex3f(-1.0, 1.0, 0.5); // Vértice superior izquierdo
	glVertex3f(-1.0, -1.0, 0.5); // Vértice inferior izquierdo
	glVertex3f(1.5, -1.0, 0.5); // Vértice inferior derecho
	glEnd();

	// Cara izquierda
	glColor3f(0.5, 1.0, 0.5); // Verde pastel
	glBegin(GL_POLYGON);
	glVertex3f(-1.0, 1.0, 0.5); // Vértice superior derecho
	glVertex3f(-1.0, 1.0, -0.5); // Vértice superior izquierdo
	glVertex3f(-1.0, -1.0, -0.5); // Vértice inferior izquierdo
	glVertex3f(-1.0, -1.0, 0.5); // Vértice inferior derecho
	glEnd();

	// Cara inferior
	glColor3f(0.8, 0.8, 0.0); // Amarillo pastel
	glBegin(GL_POLYGON);
	glVertex3f(-1.0, -1.0, -0.5); // Vértice inferior izquierdo
	glVertex3f(1.5, -1.0, -0.5); // Vértice inferior derecho
	glVertex3f(1.5, -1.0, 0.5); // Vértice superior derecho
	glVertex3f(-1.0, -1.0, 0.5); // Vértice superior izquierdo
	glEnd();
	glFlush();
}
void Polígono::DrawPiramid(int x, int y, int z)
{
	glTranslatef(x, y, z);
	glLineWidth(8.0);

	// Aplicar la escala para reducir el tamaño de la pirámide
	glScalef(0.5f, 0.5f, 0.5f); // Reduce la pirámide al 50% de su tamaño original

	glBegin(GL_TRIANGLES); // Usar triángulos para las caras de la pirámide

	// Cara frontal
	glColor3f(1.0, 0.0, 0.0); // Rojo
	glVertex3f(0.0, 1.0, 0.0); // Vértice superior
	glVertex3f(-1.0, -1.0, 1.0); // Vértice inferior izquierdo
	glVertex3f(1.0, -1.0, 1.0); // Vértice inferior derecho

	// Cara derecha
	glColor3f(0.0, 1.0, 0.0); // Verde
	glVertex3f(0.0, 1.0, 0.0); // Vértice superior
	glVertex3f(1.0, -1.0, 1.0); // Vértice inferior derecho
	glVertex3f(1.0, -1.0, -1.0); // Vértice inferior trasero derecho

	// Cara trasera
	glColor3f(0.0, 0.0, 1.0); // Azul
	glVertex3f(0.0, 1.0, 0.0); // Vértice superior
	glVertex3f(1.0, -1.0, -1.0); // Vértice inferior derecho
	glVertex3f(-1.0, -1.0, -1.0); // Vértice inferior izquierdo

	// Cara izquierda
	glColor3f(1.0, 1.0, 0.0); // Amarillo
	glVertex3f(0.0, 1.0, 0.0); // Vértice superior
	glVertex3f(-1.0, -1.0, -1.0); // Vértice inferior izquierdo
	glVertex3f(-1.0, -1.0, 1.0); // Vértice inferior izquierdo

	// Base de la pirámide
	glColor3f(0.5, 0.5, 0.5); // Gris
	glVertex3f(-1.0, -1.0, 1.0); // Vértice inferior izquierdo (frontal izquierdo)
	glVertex3f(1.0, -1.0, 1.0); // Vértice inferior derecho (frontal derecho)
	glVertex3f(1.0, -1.0, -1.0); // Vértice inferior derecho (trasero derecho)
	glVertex3f(-1.0, -1.0, -1.0); // Vértice inferior izquierdo (trasero izquierdo)

	glEnd();
	glFlush();
}
void Polígono::DrawFrustum(int x, int y, int z)
{
	// Crear un objeto de cilindro con GLU
	glTranslatef(x, y, z);
	GLUquadricObj* quadric = gluNewQuadric();

	// Configuración del tronco de cono
	glColor3f(0.0, 0.8, 0.8); // Color marrón claro

							  // Dibujar el tronco de cono
	gluCylinder(quadric, 1.0, 0.5, 2.0, 32, 32); // Radio superior, radio inferior, altura, slices, stacks

												 // Limpiar el objeto quadric
	gluDeleteQuadric(quadric);
	glFlush();
}
void Polígono::DrawIcosahedron(int x, int y, int z)
{
	glTranslatef(x, y, z);
	glLineWidth(8.0);
	glScalef(1.0f, 1.0f, 1.0f);
	glColor3f(0.7, 0.4, 0.2);
	glutSolidIcosahedron();
	glutSwapBuffers();
}

/*void Polígono::MoveForward() {
	position.z += 0.1f; // Mover hacia adelante en el eje Z
}

void Polígono::MoveBackward() {
	position.z -= 0.1f; // Mover hacia atrás en el eje Z
}

void Polígono::StrafeLeft() {
	position.x -= 0.1f; // Mover a la izquierda en el eje X
}

void Polígono::StrafeRight() {
	position.x += 0.1f; // Mover a la derecha en el eje X
}
*/


