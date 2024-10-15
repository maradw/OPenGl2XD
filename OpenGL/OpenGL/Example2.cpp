#include "Example2.h"
#include "IncludeGL.h"
#include <iostream>
// Variables globales para las transformaciones
float translateX = 0.0f;
float translateY = 0.0f;
float rotateAngle = 0.0f;
char currentFigure = '1'; 


Example2::Example2()
{
}

void Example2::init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0);
    gluLookAt(5, 5, 5, 0, 0, 0, 0, 1, 0);
    glMatrixMode(GL_MODELVIEW);
}

void Example2::Render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Aplicar transformaciones en la función Render para afectar todas las figuras
    glPushMatrix();

    glTranslatef(translateX, translateY, 0.0f);
    glRotatef(rotateAngle, 0.0f, 0.0f, 1.0f);

    // Dibuja la figura actual
    switch (currentFigure) {
    case '1':
        DrawPoint();
        break;
    case '2':
        DrawLine();
        break;
    case '3':
        XY();
        break;
    }

    glPopMatrix(); // Restaurar la matriz después de dibujar

    glutSwapBuffers(); 
}

void Example2::DrawPoint()
{
    std::cout << "DrawPoint" << std::endl;

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0f, 1.0f, 0.0f);
    glPointSize(40.0);

    glBegin(GL_POINTS);
    glVertex2f(0.0, 0.0);
    glEnd();
    glFlush();
}

void Example2::DrawLine()
{
    std::cout << "DrawLine" << std::endl;

    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(8.0f);

    glColor3f(2.0f, 1.0f, 0.0f);
    glBegin(GL_LINES);

    glVertex2f(-2.0f, -2.0f);
    glVertex2f(0.10f, 0.10f);
    glEnd();

    glFlush();
}

void Example2::XY()
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

// Funciones del teclado

void Example2::KeyboardFunc(unsigned char key, int X, int Y)
{
    switch (key)
    {
    case 'w': 
        std::cout << "Mover hacia arriba " << key << std::endl;
        translateY += 0.1f;
        break;
    case 's': 
        std::cout << "Mover hacia abajo " << key << std::endl;
        translateY -= 0.1f;
        break;
    case 'a': 
        std::cout << "Mover hacia la izquierda " << key << std::endl;
        translateX -= 0.1f;
        break;
    case 'd': 
        std::cout << "Mover hacia la derecha " << key << std::endl;
        translateX += 0.1f;
        break;
    case 'r': 
        std::cout << "Rotar hacia la derecha " << key << std::endl;
        rotateAngle += 5.0f;
        break;
    case 'l':
        std::cout << "Rotar hacia la izquierda " << key << std::endl;
        rotateAngle -= 5.0f;
        break;
    case '1':
        currentFigure = '1'; // Establece la figura actual a DrawPoint
        break;
    case '2':
        currentFigure = '2'; // Establece la figura actual a DrawLine
        break;
    case '3':
        currentFigure = '3'; // Establece la figura actual a XY
        break;
    case '4':
        exit(0);
        break;
    default:
        std::cout << "Tecla no reconocida: " << key << std::endl;
        break;
    }
    glutPostRedisplay(); // Redibuja la ventana para reflejar los cambios
}


/*void Example2::Figures(unsigned char key)
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
		XY();
		break;
	case '4':
		exit(0);
		break;
	default:
		std::cout << "Tecla no reconocida: " << key << std::endl;
		break;
	}
}*/
void Example2::Idle()
{

}