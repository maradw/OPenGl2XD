#include "Example1.h"
#include "IncludeGL.h"
#include <iostream>
Example1::Example1()
{
}

void Example1::init()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClearDepth(1.0);
	gluLookAt(5, 5, 5, 0, 0, 0, 0, 1, 0);
	glMatrixMode(GL_MODELVIEW);
	
	
	/*std::cout << "Dibujo de primitivas geometricas" << std::endl
		<< " 1: dibuja un punto" << std::endl
		<< " 2: dibuja una linea" << std::endl
		<< " 3: dibuja una linea con color" << std::endl
		<< " 4: dibuja una cadena de lineas" << std::endl
		<< " 5: dibuja los ejes XY" << std::endl
		<< " 6: dibuja los ejes XYZ" << std::endl
		<< " 7: dibuja una grid XZ" << std::endl
		<< std::flush;*/
}

void Example1::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	
}

void Example1::DrawPolyhedron()
{
	float x1 = -0.5f, y1 = 0.0f, z1 = -1.0f;  // Esquina inferior izquierda del lado ancho
	float x2 = 0.5f, y2 = 0.0f, z2 = -1.0f;   // Esquina inferior derecha del lado ancho
	float x3 = 0.0f, y3 = 0.0f, z3 = 1.0f;    // Extremo puntiagudo en el lado estrecho (una sola esquina)
	float height = 0.6f;                      // Altura del prisma

											  // Dibujar las caras del pedazo de torta
	glBegin(GL_QUADS);

	// Cara inferior (base) - Verde
	glColor3f(0.0f, 1.0f, 0.0f);  // Verde
	glVertex3f(x1, y1, z1); glVertex3f(x2, y2, z2);
	glVertex3f(x3, y3, z3); glVertex3f(x3, y3, z3); // Se cierra en el punto

													// Cara superior (tapa) - Azul
	glColor3f(0.0f, 0.0f, 1.0f);  // Azul
	glVertex3f(x1, y1 + height, z1); glVertex3f(x2, y2 + height, z2);
	glVertex3f(x3, y3 + height, z3); glVertex3f(x3, y3 + height, z3);

	// Lado frontal - Rojo
	glColor3f(1.0f, 0.0f, 0.0f);  // Rojo
	glVertex3f(x1, y1, z1); glVertex3f(x2, y2, z2);
	glVertex3f(x2, y2 + height, z2); glVertex3f(x1, y1 + height, z1);

	// Lado trasero (único punto convergente) - Amarillo
	glColor3f(1.0f, 1.0f, 0.0f);  // Amarillo
	glVertex3f(x3, y3, z3); glVertex3f(x3, y3, z3);
	glVertex3f(x3, y3 + height, z3); glVertex3f(x3, y3 + height, z3);

	// Lado izquierdo - Naranja
	glColor3f(1.0f, 0.5f, 0.0f);  // Naranja
	glVertex3f(x1, y1, z1); glVertex3f(x3, y3, z3);
	glVertex3f(x3, y3 + height, z3); glVertex3f(x1, y1 + height, z1);

	// Lado derecho - Violeta
	glColor3f(0.6f, 0.0f, 0.8f);  // Violeta
	glVertex3f(x2, y2, z2); glVertex3f(x3, y3, z3);
	glVertex3f(x3, y3 + height, z3); glVertex3f(x2, y2 + height, z2);

	glEnd();
	glFlush();
}

void Example1::DrawFrustum()
{
	// Crear un objeto de cilindro con GLU
	GLUquadricObj* quadric = gluNewQuadric();

	// Configuración del tronco de cono
	glColor3f(0.0, 0.8, 0.8); // Color marrón claro

							  // Dibujar el tronco de cono
	gluCylinder(quadric, 1.0, 0.5, 2.0, 32, 32); // Radio superior, radio inferior, altura, slices, stacks

												 // Limpiar el objeto quadric
	gluDeleteQuadric(quadric);
	glFlush();
}

void Example1::DrawCone()
{
	// Crear un objeto de cilindro con GLU
	GLUquadricObj* quadric = gluNewQuadric();

	// Configuración del cono
	glColor3f(1.0, 0.0, 0.0); // Color rojo brillante

							  // Dibujar el cono
	gluCylinder(quadric, 1.0, 0.0, 2.0, 32, 32); // Radio superior, radio inferior (0 para cono), altura, slices, stacks

												 // Limpiar el objeto quadric
	gluDeleteQuadric(quadric);
	glFlush();
}

void Example1::DrawCylinder()
{
	// Crear un objeto de cilindro con GLU
	GLUquadricObj* quadric = gluNewQuadric();

	// Configuración del cilindro
	glColor3f(0.0, 0.8, 0.6);

							  // Dibujar el cilindro
	gluCylinder(quadric, 1.0, 1.0, 2.0, 32, 32); // Radio superior, radio inferior, altura, slices, stacks

												 // Limpiar el objeto quadric
	gluDeleteQuadric(quadric);

	glFlush();
}

void Example1::DrawSphere()
{
	// Crear un objeto de esfera con GLU
	GLUquadricObj* quadric = gluNewQuadric();

	// Configuración de la esfera
	glColor3f(0.0, 0.5, 1.0); // Color azul claro

							  // Dibuja la esfera
	gluSphere(quadric, 1.0, 32, 32); // Radio, slices, stacks

									 // Limpiar el objeto quadric
	gluDeleteQuadric(quadric);
	glFlush();
}

void Example1::DrawParallelepiped()
{
	float width = 2.0;
	float height = 1.0;
	float depth = 1.5;
	// Colores para cada cara
	glColor3f(0.8, 0.3, 0.3); // Rojo claro
							  // Cara frontal
	glBegin(GL_POLYGON);
	glVertex3f(-width / 2, -height / 2, depth / 2); // Vértice inferior izquierdo
	glVertex3f(width / 2, -height / 2, depth / 2); // Vértice inferior derecho
	glVertex3f(width / 2, height / 2, depth / 2); // Vértice superior derecho
	glVertex3f(-width / 2, height / 2, depth / 2); // Vértice superior izquierdo
	glEnd();

	glColor3f(0.3, 0.8, 0.3); // Verde claro
							  // Cara trasera
	glBegin(GL_POLYGON);
	glVertex3f(-width / 2, -height / 2, -depth / 2); // Vértice inferior izquierdo
	glVertex3f(width / 2, -height / 2, -depth / 2); // Vértice inferior derecho
	glVertex3f(width / 2, height / 2, -depth / 2); // Vértice superior derecho
	glVertex3f(-width / 2, height / 2, -depth / 2); // Vértice superior izquierdo
	glEnd();

	glColor3f(0.3, 0.3, 0.8); // Azul claro
							  // Cara superior
	glBegin(GL_POLYGON);
	glVertex3f(-width / 2, height / 2, depth / 2); // Vértice frontal izquierdo
	glVertex3f(width / 2, height / 2, depth / 2); // Vértice frontal derecho
	glVertex3f(width / 2, height / 2, -depth / 2); // Vértice trasero derecho
	glVertex3f(-width / 2, height / 2, -depth / 2); // Vértice trasero izquierdo
	glEnd();

	glColor3f(0.8, 0.8, 0.3); // Amarillo claro
							  // Cara inferior
	glBegin(GL_POLYGON);
	glVertex3f(-width / 2, -height / 2, depth / 2); // Vértice frontal izquierdo
	glVertex3f(width / 2, -height / 2, depth / 2); // Vértice frontal derecho
	glVertex3f(width / 2, -height / 2, -depth / 2); // Vértice trasero derecho
	glVertex3f(-width / 2, -height / 2, -depth / 2); // Vértice trasero izquierdo
	glEnd();

	glColor3f(0.8, 0.3, 0.8); // Morado claro
							  // Cara derecha
	glBegin(GL_POLYGON);
	glVertex3f(width / 2, -height / 2, depth / 2); // Vértice frontal inferior
	glVertex3f(width / 2, -height / 2, -depth / 2); // Vértice trasero inferior
	glVertex3f(width / 2, height / 2, -depth / 2); // Vértice trasero superior
	glVertex3f(width / 2, height / 2, depth / 2); // Vértice frontal superior
	glEnd();

	glColor3f(0.3, 0.8, 0.8); // Cian claro
							  // Cara izquierda
	glBegin(GL_POLYGON);
	glVertex3f(-width / 2, -height / 2, depth / 2); // Vértice frontal inferior
	glVertex3f(-width / 2, -height / 2, -depth / 2); // Vértice trasero inferior
	glVertex3f(-width / 2, height / 2, -depth / 2); // Vértice trasero superior
	glVertex3f(-width / 2, height / 2, depth / 2); // Vértice frontal superior
	glEnd();
	glFlush();
}

void Example1::DrawOrthohedron()
{
	glColor3f(0.5, 0.2, 0.8); // Morado
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

void Example1::DrawPrism()
{
	glColor3f(0.7, 0.7, 0.7); // Gris claro

							  // Base superior (rectángulo)
	glBegin(GL_POLYGON);
	glVertex3f(-1.0, 1.0, -0.5);
	glVertex3f(1.0, 1.0, -0.5);
	glVertex3f(1.0, 1.0, 0.5);
	glVertex3f(-1.0, 1.0, 0.5);
	glEnd();

	// Base inferior (rectángulo)
	glBegin(GL_POLYGON);
	glVertex3f(-1.0, -1.0, -0.5);
	glVertex3f(1.0, -1.0, -0.5);
	glVertex3f(1.0, -1.0, 0.5);
	glVertex3f(-1.0, -1.0, 0.5);
	glEnd();

	// Cara frontal
	glColor3f(1.0, 0.0, 0.0); // Rojo
	glBegin(GL_POLYGON);
	glVertex3f(-1.0, 1.0, -0.5);
	glVertex3f(1.0, 1.0, -0.5);
	glVertex3f(1.0, -1.0, -0.5);
	glVertex3f(-1.0, -1.0, -0.5);
	glEnd();

	// Cara derecha
	glColor3f(0.0, 1.0, 0.0); // Verde
	glBegin(GL_POLYGON);
	glVertex3f(1.0, 1.0, -0.5);
	glVertex3f(1.0, 1.0, 0.5);
	glVertex3f(1.0, -1.0, 0.5);
	glVertex3f(1.0, -1.0, -0.5);
	glEnd();

	// Cara trasera
	glColor3f(0.0, 0.0, 1.0); // Azul
	glBegin(GL_POLYGON);
	glVertex3f(1.0, 1.0, 0.5);
	glVertex3f(-1.0, 1.0, 0.5);
	glVertex3f(-1.0, -1.0, 0.5);
	glVertex3f(1.0, -1.0, 0.5);
	glEnd();

	// Cara izquierda
	glColor3f(1.0, 1.0, 0.0); // Amarillo
	glBegin(GL_POLYGON);
	glVertex3f(-1.0, 1.0, 0.5);
	glVertex3f(-1.0, 1.0, -0.5);
	glVertex3f(-1.0, -1.0, -0.5);
	glVertex3f(-1.0, -1.0, 0.5);
	glEnd();

	// Cara inferior
	glColor3f(1.0, 0.5, 0.0); // Naranja
	glBegin(GL_POLYGON);
	glVertex3f(-1.0, -1.0, -0.5);
	glVertex3f(1.0, -1.0, -0.5);
	glVertex3f(1.0, -1.0, 0.5);
	glVertex3f(-1.0, -1.0, 0.5);
	glEnd();
	glFlush();
}
	
void Example1::DrawTruncatedPyramid()
{
	glColor3f(0.75, 0.0, 0.75); // Lila

								// Base superior (pequeña) - pentágono
	glBegin(GL_POLYGON);
	glVertex3f(-0.5, 1.0, -0.5);
	glVertex3f(0.5, 1.0, -0.5);
	glVertex3f(0.7, 1.0, 0.0);
	glVertex3f(0.5, 1.0, 0.5);
	glVertex3f(-0.5, 1.0, 0.5);
	glEnd();

	// Cara frontal
	glColor3f(1.0, 0.0, 0.0); // Rojo
	glBegin(GL_TRIANGLES);
	glVertex3f(-0.5, 1.0, -0.5); // Vértice superior de la base superior
	glVertex3f(-1.0, -1.0, -1.0); // Vértice inferior izquierdo
	glVertex3f(0.5, 1.0, -0.5); // Vértice superior derecho
	glEnd();

	// Cara derecha
	glColor3f(0.0, 1.0, 0.0); // Verde
	glBegin(GL_TRIANGLES);
	glVertex3f(0.5, 1.0, -0.5); // Vértice superior de la base superior
	glVertex3f(1.0, -1.0, -1.0); // Vértice inferior derecho
	glVertex3f(0.7, 1.0, 0.0); // Vértice superior derecho
	glEnd();

	// Cara trasera
	glColor3f(0.0, 0.0, 1.0); // Azul
	glBegin(GL_TRIANGLES);
	glVertex3f(0.7, 1.0, 0.0); // Vértice superior derecho
	glVertex3f(1.0, -1.0, 1.0); // Vértice inferior derecho
	glVertex3f(0.5, 1.0, 0.5); // Vértice superior derecho de la base superior
	glEnd();

	// Cara izquierda
	glColor3f(1.0, 1.0, 0.0); // Amarillo
	glBegin(GL_TRIANGLES);
	glVertex3f(0.5, 1.0, 0.5); // Vértice superior de la base superior
	glVertex3f(-1.0, -1.0, 1.0); // Vértice inferior izquierdo
	glVertex3f(-0.5, 1.0, 0.5); // Vértice superior izquierdo
	glEnd();

	// Base inferior
	glColor3f(0.5, 0.5, 0.5); // Gris
	glBegin(GL_POLYGON);
	glVertex3f(-1.0, -1.0, -1.0);
	glVertex3f(1.0, -1.0, -1.0);
	glVertex3f(1.0, -1.0, 1.0);
	glVertex3f(-1.0, -1.0, 1.0);
	glEnd();
	glFlush();
}
void Example1::DrawPiramid()
{
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
void Example1::DrawDodecahedron()
{
	glColor3f(0.5, 1.0, 0.5);  // Color verde claro para el dodecaedro
	glutSolidDodecahedron();    // Dibujar el dodecaedro

	glutSwapBuffers();
}
void Example1::DrawOctahedron()
{
	glColor3f(0.5, 0.5, 1.0);  // Color azul claro para el octaedro
	glutSolidOctahedron();      // Dibujar el octaedro

	glutSwapBuffers();
}
void Example1::DrawIcosahedron()
{
	glColor3f(0.7, 0.4, 0.2);
	glutSolidIcosahedron();
	glutSwapBuffers();
}
void Example1::DrawTetrahedron()
{
	glBegin(GL_TRIANGLES); // Usar triángulos para cada cara

						   // Cara 1
	glColor3f(1.0, 0.0, 0.0); // Rojo
	glVertex3f(0.0, 1.0, 0.0); // Vértice superior
	glVertex3f(-1.0, -1.0, 1.0); // Base izquierda
	glVertex3f(1.0, -1.0, 1.0); // Base derecha

								// Cara 2
	glColor3f(0.0, 1.0, 0.0); // Verde
	glVertex3f(0.0, 1.0, 0.0); // Vértice superior
	glVertex3f(1.0, -1.0, 1.0); // Base derecha
	glVertex3f(0.0, -1.0, -1.0); // Base trasera

								 // Cara 3
	glColor3f(0.0, 0.0, 1.0); // Azul
	glVertex3f(0.0, 1.0, 0.0); // Vértice superior
	glVertex3f(0.0, -1.0, -1.0); // Base trasera
	glVertex3f(-1.0, -1.0, 1.0); // Base izquierda

								 // Cara 4 (base)
	glColor3f(1.0, 1.0, 0.0); // Amarillo
	glVertex3f(-1.0, -1.0, 1.0); // Base izquierda
	glVertex3f(1.0, -1.0, 1.0); // Base derecha
	glVertex3f(0.0, -1.0, -1.0); // Base trasera

	glEnd();
	glFlush();
}
void Example1::DrawCube()
{
	glLineWidth(8.0);
	glClear(GL_COLOR_BUFFER_BIT);
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
void Example1::DrawPoint()
{
	std::cout << "DrawPoint" << std::endl;

	glScalef(1.5f, 1.5f, 1.5f);  // Escalamiento
	glRotatef(19.0f, 0.0f, 0.0f, 1.0f);  // Rotación de 45 grados alrededor del eje z
	glTranslatef(2.0f, 1.0f, 0.0f);

	glClear(GL_COLOR_BUFFER_BIT); 
	glPointSize(30.0);
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_POINTS); 
	glVertex2f(0.0, 0.0); 
	glEnd();
	glFlush(); 
	 
	
}
void Example1::DrawLine()
{
	std::cout << "DrawLine" << std::endl;
	glScalef(1.5f, 1.5f, 1.5f);  // Escalamiento
	glRotatef(19.0f, 0.0f, 0.0f, 1.0f);  // Rotación de 45 grados alrededor del eje z
	glTranslatef(2.0f, 1.0f, 0.0f);
	glLineWidth(8.0);
	glClear(GL_COLOR_BUFFER_BIT); 
	glBegin(GL_LINES); 
	glVertex2f(-2.0f, -2.0f); 
	glVertex2f(0.10f, 0.10f);
	glEnd(); 

	glFlush();

}
void Example1::DrawColoredLine()
{
	std::cout << "DrawColoredLine" << std::endl;
	glLineWidth(8.0);
	glClear(GL_COLOR_BUFFER_BIT); 
	glColor3f(0.80f, 0.0f, 1.0f);
	glBegin(GL_LINES);
	glVertex2f(-2.0f, -2.0f);
	glVertex2f(0.10f, 0.10f);
	glEnd();

	glFlush();
}
void Example1::DrawLineChain()
{
	std::cout << "DrawLineChain" << std::endl;
	glLineWidth(8.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.2f, 0.6f, 0.4f);

	glBegin(GL_LINES);

	glVertex2f(-0.5f, -0.5f);
	glVertex2f(-0.2f, 0.2f);

	glVertex2f(-0.2f, 0.2f);
	glVertex2f(0.2f, 0.2f);

	glVertex2f(0.2f, 0.2f);
	glVertex2f(0.5f, -0.5f);

	glEnd();

	glFlush();

}

void Example1::XY()
{
	std::cout << "DrawXYAxis" << std::endl;
	glLineWidth(8.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);

	//Eje X
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-1.0f, 0.0f);
	glVertex2f(1.0f, 0.0f); 

	//Eje Y
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(0.0f, -1.0f); 
	glVertex2f(0.0f, 1.0f);

	glEnd();
	glFlush();
	
}

void Example1::XYZ()
{
	std::cout << "DrawXYZAxis" << std::endl;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLineWidth(8.0);
	glBegin(GL_LINES);

	//Eje X
	glColor3f(1.0f, 0.0f, 0.0f); 
	glVertex3f(-1.0f, 0.0f, 0.0f); 
	glVertex3f(1.0f, 0.0f, 0.0f); 

	//Eje Y
	glColor3f(0.0f, 1.0f, 0.0f); 
	glVertex3f(0.0f, -1.0f, 0.0f); 
	glVertex3f(0.0f, 1.0f, 0.0f); 

	//Eje Z
	glColor3f(0.0f, 0.0f, 1.0f); 
	glVertex3f(0.0f, 0.0f, -1.0f);
	glVertex3f(0.0f, 0.0f, 1.0f);

	glEnd();

	glutSwapBuffers();
}

void Example1::Grid()
{
	std::cout << "DrawGrid" << std::endl;
	glLineWidth(3.0);
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

	glutSwapBuffers();
}

void Example1::KeyboardFunc(unsigned char key, int X, int Y)
{
	Figures(key);
}

void Example1::Figures(unsigned char key)
{
	switch (key)
	{
	case '1':
		DrawPoint();
		break;
	case '2':
		DrawLine();
		break;
	case '3':
		DrawColoredLine();
		break;
	case '4':
		DrawLineChain();
		break;
	case '5':
		XY();
		break;
	case '6':
		XYZ();
		break;
	case '7':
		Grid();
		break;
	case '8':
		exit(0);
		break;
	default:
		std::cout << "Tecla no reconocida: " << key << std::endl;
		break;
	}
}


void Example1::Idle()
{

}