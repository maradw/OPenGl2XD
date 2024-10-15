#include "PointLight.h"
#include "IncludeGL.h"
#include <iostream>
PointLight::PointLight()
{

}
void PointLight::SetPointLight()
{
    glPushMatrix();
    glTranslatef(2.0f, 2.0f, 0.0f);  // Posicionar la esfera en el origen
    glutSolidSphere(0.2f, 50, 50);   // Dibujar esfera con radio 1.0, con 50 segmentos
    glPopMatrix();

 
    glEnable(GL_LIGHT0);     // Habilitar la luz 0 (punto de luz)
    // Definir propiedades de la luz puntual (point light)
    GLfloat ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    GLfloat diffuse_light[] = { 0.8f, 0.8f, 0.8f, 1.0f };
    GLfloat specular_light[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat light_position[] = { 2.0f, 2.0f, 0.0f, 1.0f };  // Posición de la luz (1.0f para luz puntual)
   
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    //glShadeModel(GL_SMOOTH);
    glShadeModel(GL_FLAT);
    properties(ambientLight, diffuse_light, specular_light,light_position);
}

