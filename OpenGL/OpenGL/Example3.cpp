#include "Example3.h"
#include "IncludeGL.h"
#include <GL/glut.h>
#include <iostream>
#include "Figura.h"

float transX = 0.0f;
float transY = 0.0f;
float transZ = 0.0f;
float rotAngle = 0.0f;

Example3::Example3() : objectPosition(0, 0, 0)
{
    camera = new Camera();
}
void Example3::init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0);
    glEnable(GL_DEPTH_TEST); 
    camera->Init();
    glMatrixMode(GL_MODELVIEW);
   //camera->SetPosition(Vector3(0, 2, 8));
   //camera->LookAt(Vector3(transX, transY, transZ),5.0f);
}
void Example3::Render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    camera->LookAt(Vector3(transX, transY, transZ), 5.0f);
    camera->Update();
    DrawAxis(30, 2);
    DrawGrids(1);
    
    polygon->DrawPiramid(2, 1, 1);
    polygon->DrawIcosahedron(4, 1, 1);
    glRotatef(rotAngle, 0.0f, 0.0f, 1.0f);
    glTranslatef(transX, transY, transZ);  // Aplica la traslación al cubo
    polygon->DrawCube(transX, transY, transZ);

    glutSwapBuffers();
}

void Example3::KeyboardFunc(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w':
        camera->MoveForward();
        break;
    case 's':
        camera->MoveBackward();
        break;
    case 'a':
        camera->StrafeLeft();
        break;
    case 'd':
        camera->StrafeRight();
        break;
    case 'z':
        camera->Rotate(-1.0f, 0.0f); 
        break;
    case 'x':
        camera->Rotate(1.0f, 0.0f); 
        break;
    case 'c':
        camera->Rotate(0.0f, -1.0f);
        break;
    case 'v':
        camera->Rotate(0.0f, 1.0f);
        break;
    case 'k':
        std::cout << "Mover hacia atras " << key << std::endl;
        transZ += 0.1f;
        break;
    case 'i':
        std::cout << "Mover hacia adelante " << key << std::endl;
        transZ -= 0.1f;
        break;
    case 'j':
        std::cout << "Mover hacia la izquierda " << key << std::endl;
        transX -= 0.1f;
        break;
    case 'l':
        std::cout << "Mover hacia la derecha " << key << std::endl;
        transX += 0.1f;
        break;
    case 'p':
        std::cout << "Rotar hacia la derecha " << key << std::endl;
        rotAngle += 5.0f;
        break;
        case 't':
        std::cout << "Mover hacia la arriba " << key << std::endl;
        transY += 0.1f;
        break;
    case 'g':
        std::cout << "Rotar hacia la izquierda " << key << std::endl;
        transY -= 0.1f;
        break;
    
    }


    glutPostRedisplay();
}

void Example3::TPSKeyboardFunc(unsigned char key, int x, int y)
{
    switch (key)
    {
        /*case 'r': // Mover objeto a la izquierda
            MoveObject(-0.1f, 0); // Mover 0.1 unidades a la izquierda
            break;
        case 't': // Mover objeto a la derecha
            MoveObject(0.1f, 0); // Mover 0.1 unidades a la derecha
            break;
        case 'u': // Mover objeto hacia adelante
            MoveObject(0, -0.1f); // Mover 0.1 unidades hacia adelante
            break;
        case 'i': // Mover objeto hacia atrás
            MoveObject(0, 0.1f); // Mover 0.1 unidades hacia atrás
            break;
        }
    */

    /*case 'h':
        std::cout << "Mover hacia arriba " << key << std::endl;
        transY += 0.1f;
        break;
    case 'j':
        std::cout << "Mover hacia abajo " << key << std::endl;
        transY -= 0.1f;
        break;
    case 'k':
        std::cout << "Mover hacia la izquierda " << key << std::endl;
        transX -= 0.1f;
        break;
    case 'l':
        std::cout << "Mover hacia la derecha " << key << std::endl;
        transX += 0.1f;
        break;
    case 'p':
        std::cout << "Rotar hacia la derecha " << key << std::endl;
        rotAngle += 5.0f;
        break;*/


        /*case '1':
       camera->MoveForward();
       break;
   case '2':
       camera->MoveBackward();
       break;
   case '3':
       camera->StrafeLeft();
       break;
   case '4':
       camera->StrafeRight();
       break;
   case GLUT_KEY_LEFT:
       camera->Rotate(-1.0f, 0.0f); // Rotar a la izquierda
       break;
   case GLUT_KEY_RIGHT:
       camera->Rotate(1.0f, 0.0f);  // Rotar a la derecha
       break;
   case GLUT_KEY_UP:
       camera->Rotate(0.0f, -1.0f); // Rotar hacia arriba
       break;
   case GLUT_KEY_DOWN:
       camera->Rotate(0.0f, 1.0f);  // Rotar hacia abajo
       break;*/
        glutPostRedisplay();
    }
}
/*void Example3::MoveObject(int dx, int dz) 
{
    objectPosition.x += dx; // Cambiar la posición en X
    objectPosition.z += dz; // Cambiar la posición en Z
}
*/
void Example3::Idle()
{
    // Aquí puedes agregar animaciones si es necesario
}