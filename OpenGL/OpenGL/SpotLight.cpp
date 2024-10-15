#include "SpotLight.h"
#include "IncludeGL.h"
#include <iostream>
SpotLight::SpotLight()
{

}
void SpotLight::SetSpotLight() {
    glPushMatrix();
    glTranslatef(-2.0f, 2.0f, 0.0f);  // Posicionar la esfera en el origen
    glutSolidSphere(0.2f, 50, 50);   // Dibujar esfera con radio 1.0, con 50 segmentos
    glPopMatrix();
   
    glEnable(GL_LIGHT1);     // Habilitar la luz 0 (spotlight)
    // Definir propiedades de la luz spotlight
    GLfloat ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    GLfloat diffuse_light[] = { 0.8f, 0.8f, 0.8f, 1.0f };
    GLfloat specular_light[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat light_position[] = { -2.0f, 2.0f, 0.0f, 1.0f };  // Posición del spotlight


    // Definir dirección y ángulo del spotlight
    GLfloat direccion_luz[] = { 0.0f, -1.0f, 0.0f };  // Dirección hacia abajo
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, direccion_luz);
    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 45.0f);    // Ángulo del foco (45 grados)
    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 2.0f);   // Atenuación del spotlight
    // Habilitar el sombreado suave
    glShadeModel(GL_SMOOTH);
    properties(ambientLight, diffuse_light, specular_light, light_position);
}
