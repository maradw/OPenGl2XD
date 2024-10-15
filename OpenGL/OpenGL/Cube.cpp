#include "Cube.h"
#include "IncludeGL.h"
#include <iostream>

Vector3 position;
Polígono::Polígono()
{

}
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
void Polígono::DrawCube1() {
    glPushMatrix(); // Guardar la matriz de transformación actual
    glTranslatef(position.x, position.y, position.z); // Aplicar la transformación a la posición del cubo

    glBegin(GL_QUADS);
    // Aquí iría el código para dibujar el cubo (como lo tenías antes)
    glEnd();

    glPopMatrix(); // Restaurar la matriz de transformación
}

void Polígono::KeyboardFunc(unsigned char key, int x, int y)
{

}
void Polígono::MoveForward() {
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