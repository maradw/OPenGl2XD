#include "Lights.h"
#include "IncludeGL.h"
#include <iostream>

Lights::Lights()
{

}
void Lights::init()
{
    glEnable(GL_LIGHTING);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0);
    glEnable(GL_DEPTH_TEST);
    gluLookAt(5, 5, 5, 0, 0, 0, 0, 1, 0);
    glMatrixMode(GL_MODELVIEW);
}
void Lights::SetPosition(GLenum lightID, GLfloat x, GLfloat y, GLfloat z, GLfloat w) 
{
    GLfloat position[] = { x, y, z, w };
    glLightfv(lightID, GL_POSITION, position);
}
void Lights::properties(GLfloat ambientLight[], GLfloat diffuse_light[], GLfloat specular_light[],GLfloat light_position[])
{
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

}


