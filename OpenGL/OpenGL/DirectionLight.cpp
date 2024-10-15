#include "DirectionLight.h"
#include "IncludeGL.h"
#include <iostream>
DirectionLight::DirectionLight()
{

}
void DirectionLight::SetDirectionLight() {
    glEnable(GL_LIGHT0);     // Habilitar la luz 0 (luz direccional)
    // Definir propiedades de la luz direccional
    GLfloat ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    GLfloat diffuse_light[] = { 0.8f, 0.8f, 0.8f, 1.0f };
    GLfloat specular_light[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    // Definir la dirección de la luz
    GLfloat directionLight[] = { 1.0f, -1.0f, -1.0f, 0.0f };  // (x, y, z, 0.0f para luz direccional)
    // Configurar la luz 0
    properties(ambientLight, diffuse_light, specular_light, directionLight);
    // Habilitar el sombreado suave
    glShadeModel(GL_SMOOTH);
}