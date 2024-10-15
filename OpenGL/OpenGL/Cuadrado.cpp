#include "Cuadrado.h"
#include "IncludeGL.h"
#include <iostream>
Cuadrado::Cuadrado()
{

}
void Cuadrado::init()
{

}
void Cuadrado::Draw()
{
    //glClear(GL_COLOR_BUFFER_BIT);
    //glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 1.0, 0.0);

    glBegin(GL_QUADS);
    glVertex2f(-0.5, -0.5);
    glVertex2f(0.5, -0.5);
    glVertex2f(0.5, 0.5);
    glVertex2f(-0.5, 0.5);
    glEnd();
    glFlush();

    
}
void Cuadrado::CalculateArea() {

}
void Cuadrado::CalculatePerimeter() {

}
