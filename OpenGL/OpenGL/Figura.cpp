#include "Figura.h"
#include "IncludeGL.h"
#include <GL/glut.h>
#include <iostream>
Figura::Figura(const std::string& name, int w, float r, float g, float b)
    : nameF(name), width(w) 
{
    color[0] = r;  // Inicializa el color RGB como float
    color[1] = g;
    color[2] = b;
}
Figura::Figura() {

}

void Figura::init()
{
    // PointLight pointLight;


     //pointLight.init();


}
void Figura:: Draw() 
{
    glBegin(GL_QUADS);  // Dibujar un cuadrado
    glVertex2f(-width / 2, -width / 2);  // Primer vértice
    glVertex2f(width / 2, -width / 2);   // Segundo vértice
    glVertex2f(width / 2, width / 2);    // Tercer vértice
    glVertex2f(-width / 2, width / 2);   // Cuarto vértice
    glEnd();
}

