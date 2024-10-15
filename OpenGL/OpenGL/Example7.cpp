#include "Example7.h"
#include "IncludeGL.h"
#include <iostream>
Example7::Example7()
{

}

void Example7::init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0);
    gluLookAt(5, 5, 5, 0, 0, 0, 0, 1, 0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_MODELVIEW);

}
void Example7::Render() 
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    DrawQuad2();
    






   


}
void Example7::DrawCube2() 
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   // Define vertices of the cube
   GLfloat vertices[] = {
       // Front face
       -0.5f, -0.5f,  0.5f,
        0.5f, -0.5f,  0.5f,
        0.5f,  0.5f,  0.5f,
       -0.5f,  0.5f,  0.5f,
       // Back face
       -0.5f, -0.5f, -0.5f,
        0.5f, -0.5f, -0.5f,
        0.5f,  0.5f, -0.5f,
       -0.5f,  0.5f, -0.5f,
   };

   // Define the indices for the cube (6 faces, 2 triangles per face)
   GLuint indices[] = {
       // Front face
       0, 1, 2, 2, 3, 0,
       // Back face
       4, 5, 6, 6, 7, 4,
       // Top face
       3, 2, 6, 6, 7, 3,
       // Bottom face
       0, 4, 5, 5, 1, 0,
       // Right face
       1, 5, 6, 6, 2, 1,
       // Left face
       0, 3, 7, 7, 4, 0
   };

   // Enable the vertex array
   glEnableClientState(GL_VERTEX_ARRAY);

   // Define the vertex array
   glVertexPointer(3, GL_FLOAT, 0, vertices);

   // Draw the cube using indexed drawing
   glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(GLuint), GL_UNSIGNED_INT, indices);

   // Disable the vertex array
   glDisableClientState(GL_VERTEX_ARRAY);

   // Flush the OpenGL commands
   glFlush();
}
void Example7::DrawQuad2()
{

    GLfloat quad[] = {
        -0.5f, -0.5f, // Vértice inferior izquierdo
        0.5f, -0.5f, // Vértice inferior derecho
        0.5f,  0.5f, // Vértice superior derecho
        -0.5f,  0.5f  // Vértice superior izquierdo
    };
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, quad);
    glDrawArrays(GL_QUADS, 0, 4);
    glDisableClientState(GL_VERTEX_ARRAY);
    glFlush();
}
void Example7::KeyboardFunc(unsigned char key, int X, int Y)
{

}
void Example7::Idle() 
{
}

