#include "Triangulo.h"
#include "IncludeGL.h"
#include <iostream>
Triangulo::Triangulo()
{

}
void Triangulo::init()
{

}
void Triangulo::Draw()
{
    //glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 1.0f, 0.0f);

    glBegin(GL_TRIANGLES);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.0f, 0.5f);
    glEnd();
    glFlush();

}
void Triangulo::CalculateArea() {

}
void Triangulo::CalculatePerimeter() {

}
