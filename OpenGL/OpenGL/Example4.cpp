#include "Example4.h"
#include "IncludeGL.h"
#include <iostream>
#include "PointLight.h"
Example4::Example4()
{

}
void Example4::init()
{
   // PointLight pointLight;

    
    //pointLight.init();


}
/*void Example4::xd() {
    PointLight pointLight;

    // Inicializar la escena (habilitar iluminación global)
    pointLight.init();

    // Configurar las propiedades de la luz puntual
    pointLight.setLight();

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0);
    glEnable(GL_DEPTH_TEST);
    gluLookAt(5, 5, 5, 0, 0, 0, 0, 1, 0);
    glMatrixMode(GL_MODELVIEW);
}*/
void Example4::Render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    DrawAxis(50,2);
    // Configurar la luz y el material antes de dibujar

    SetPointLight();
    //ConfigurarLuzSpotLight();
    SetMaterial();
    // Dibujar una esfera
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);  // Posicionar la esfera en el origen
    glutSolidSphere(1.0f, 50, 50);   // Dibujar esfera con radio 1.0, con 50 segmentos
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);  // Posicionar la esfera en el origen
    //DrawPlane();   // Dibujar esfera con radio 1.0, con 50 segmentos
 
   // DrawGrids();
    //ConfigurarLuzDireccional();
    glPopMatrix();

    glFlush();
}
void Example4::DrawPlane() {
    // Dibujar un plano en el eje XZ (Y = 0)
    glBegin(GL_QUADS);  // Usamos un cuadrado (QUADS) para dibujar el plano
    glNormal3f(0.0f, 1.0f, 0.0f);  // Normal apuntando hacia arriba en el eje Y
    glVertex3f(-2.0f, 0.0f, -2.0f);  // Vértice 1
    glVertex3f(2.0f, 0.0f, -2.0f);  // Vértice 2
    glVertex3f(2.0f, 0.0f, 2.0f);  // Vértice 3
    glVertex3f(-2.0f, 0.0f, 2.0f);  // Vértice 4
    glEnd();
}

void Example4::SetMaterial() {
    // Definir propiedades del material
    GLfloat mat_ambient[] = { 0.3f, 0.3f, 0.3f, 1.0f };
    GLfloat mat_diffuse[] = { 0.6f, 0.6f, 0.6f, 1.0f };
    GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat brillo[] = { 50.0f };  // Brillo (especular)
    // Configurar el material
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, brillo);
}
void Example4::SetPointLight()
{
    glPushMatrix();
    glTranslatef(2.0f, 2.0f, 0.0f);  // Posicionar la esfera en el origen
    glutSolidSphere(0.2f, 50, 50);   // Dibujar esfera con radio 1.0, con 50 segmentos
    glPopMatrix();

    glEnable(GL_LIGHTING);   // Habilitar iluminación
    glEnable(GL_LIGHT0);     // Habilitar la luz 0 (punto de luz)
    // Definir propiedades de la luz puntual (point light)
    GLfloat ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    GLfloat diffuse_light[] = { 0.8f, 0.8f, 0.8f, 1.0f };
    GLfloat specular_light[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat light_position[] = { 2.0f, 2.0f, 0.0f, 1.0f };  // Posición de la luz (1.0f para luz puntual)
    // Configurar la luz 0
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    // Habilitar el sombreado suave
    //glShadeModel(GL_SMOOTH);
    glShadeModel(GL_FLAT);
}
void Example4::ConfigurarLuzDireccional() {
    glEnable(GL_LIGHTING);   // Habilitar iluminación
    glEnable(GL_LIGHT0);     // Habilitar la luz 0 (luz direccional)
    // Definir propiedades de la luz direccional
    GLfloat ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    GLfloat diffuse_light[] = { 0.8f, 0.8f, 0.8f, 1.0f };
    GLfloat specular_light[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    // Definir la dirección de la luz
    GLfloat direccion_luz[] = { 1.0f, -1.0f, -1.0f, 0.0f };  // (x, y, z, 0.0f para luz direccional)
    // Configurar la luz 0
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, direccion_luz);
    // Habilitar el sombreado suave
    glShadeModel(GL_SMOOTH);
}
void Example4::ConfigurarLuzSpotLight() {
    glPushMatrix();
    glTranslatef(-2.0f, 2.0f, 0.0f);  // Posicionar la esfera en el origen
    glutSolidSphere(0.2f, 50, 50);   // Dibujar esfera con radio 1.0, con 50 segmentos
    glPopMatrix();
    glEnable(GL_LIGHTING);   // Habilitar iluminación
    glEnable(GL_LIGHT1);     // Habilitar la luz 0 (spotlight)
    // Definir propiedades de la luz spotlight
    GLfloat ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    GLfloat diffuse_light[] = { 0.8f, 0.8f, 0.8f, 1.0f };
    GLfloat specular_light[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat light_position[] = { -2.0f, 2.0f, 0.0f, 1.0f };  // Posición del spotlight
    // Configurar la luz 0
    glLightfv(GL_LIGHT1, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT1, GL_POSITION, light_position);
    // Definir dirección y ángulo del spotlight
    GLfloat direccion_luz[] = { 0.0f, -1.0f, 0.0f };  // Dirección hacia abajo
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, direccion_luz);
    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 45.0f);    // Ángulo del foco (45 grados)
    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 2.0f);   // Atenuación del spotlight
    // Habilitar el sombreado suave
    glShadeModel(GL_SMOOTH);
}
void Example4::KeyboardFunc(unsigned char key, int X, int Y)
{

}
void Example4::Idle()
{
}