#include "Example6.h"
#include "IncludeGL.h"
#include <iostream>
#include "Cubo.h"
#include "Esfera.h"
int quantity;
Example6::Example6()
{

}

void Example6::init()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClearDepth(1.0);
	gluLookAt(5, 5, 5, 0, 0, 0, 0, 1, 0);
    glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_MODELVIEW);



    cubo = new Cubo();
    esfera = new Esfera();
    cuadrado = new Cuadrado();
    CreateCubeDisplayList();
    CreateSphereDisplayList();
    CreateQuadDisplayList();
}

void Example6::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    Example::DrawGrids(2);
    
    for (int i = 0; i <= 2; i++)
    {
        glPushMatrix();
        glTranslatef(i * 2.0f, 0.0f, 0.0f);
        glCallList(cubeList);

        glTranslatef(i * -4.0f, 0.0f, 0.0f);
        glCallList(sphereList);

        glTranslatef( -2.0f, i * 1.5f, -5.0f);
        glCallList(quadList);
        glPopMatrix();
    }
    glutSwapBuffers();
}
void Example6::KeyboardFunc(unsigned char key, int x, int y)
{

}
void Example6::CreateSphereDisplayList() 
{
    sphereList = glGenLists(1);
    glNewList(sphereList, GL_COMPILE);


    esfera->Draw();
   

    glEndList();


}
void Example6::CreateCubeDisplayList() 
{
    cubeList = glGenLists(1);
   glNewList(cubeList, GL_COMPILE);
  
 
   cubo->Draw();


    glEndList();

    
}
void Example6::CreateQuadDisplayList()
{
    quadList = glGenLists(1);
    glNewList(quadList, GL_COMPILE);


    cuadrado->Draw();


    glEndList();


}

void Example6::Idle()
{

}

