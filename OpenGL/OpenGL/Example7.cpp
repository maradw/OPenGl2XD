#include "Example7.h"
#include "IncludeGL.h"
#include <iostream>

#include "vector"
#define M_PI 3.14159265358979323846
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
        // Front 
        0, 1, 2, 2, 3, 0,
        // Back
        4, 5, 6, 6, 7, 4,
        // Top
        3, 2, 6, 6, 7, 3,
        // Bottom
        0, 4, 5, 5, 1, 0,
        // Right
        1, 5, 6, 6, 2, 1,
        // Left
        0, 3, 7, 7, 4, 0
    };

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(GLuint), GL_UNSIGNED_INT, indices);
    glDisableClientState(GL_VERTEX_ARRAY);
    glFlush();
}
//array simple
void Example7::DrawCube3Sim()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Desactivar temporalmente back-face culling para verificar las caras
    glDisable(GL_CULL_FACE);

    // Define vertices of the cube (each triangle is defined separately)
    GLfloat vertices[] = {
        // Front face
        -0.5f, -0.5f,  0.5f, // Triangle 1
         0.5f, -0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f, // Triangle 2
        -0.5f,  0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,

         // Back face
         -0.5f, -0.5f, -0.5f, // Triangle 3
          0.5f, -0.5f, -0.5f,
          0.5f,  0.5f, -0.5f,
         -0.5f,  0.5f, -0.5f, // Triangle 4
         -0.5f,  0.5f, -0.5f,
          0.5f,  0.5f, -0.5f,

          // Top face (corrected winding order)
          -0.5f,  0.5f,  0.5f, // Triangle 5
           0.5f,  0.5f,  0.5f,
          -0.5f,  0.5f, -0.5f,
           0.5f,  0.5f,  0.5f, // Triangle 6 (order corrected)
           0.5f,  0.5f, -0.5f,
          -0.5f,  0.5f, -0.5f,

          // Bottom face
          -0.5f, -0.5f,  0.5f, // Triangle 7
          -0.5f, -0.5f, -0.5f,
           0.5f, -0.5f, -0.5f,
          -0.5f, -0.5f,  0.5f, // Triangle 8
           0.5f, -0.5f, -0.5f,
           0.5f, -0.5f,  0.5f,

           // Right face
            0.5f, -0.5f, -0.5f, // Triangle 9
            0.5f, -0.5f,  0.5f,
            0.5f,  0.5f,  0.5f,
            0.5f, -0.5f, -0.5f, // Triangle 10
            0.5f,  0.5f,  0.5f,
            0.5f,  0.5f, -0.5f,

            // Left face
            -0.5f, -0.5f, -0.5f, // Triangle 11
            -0.5f, -0.5f,  0.5f,
            -0.5f,  0.5f,  0.5f,
            -0.5f, -0.5f, -0.5f, // Triangle 12
            -0.5f,  0.5f,  0.5f,
            -0.5f,  0.5f, -0.5f,
    };

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glDrawArrays(GL_TRIANGLES, 0, sizeof(vertices) / sizeof(GLfloat) / 3);
    glDisableClientState(GL_VERTEX_ARRAY);
    glFlush();
}
//array simple
void Example7::DrawQuad2()
{

    GLfloat quad[] = {
        -0.5f, -0.5f, // V�rtice inferior izquierdo
        0.5f, -0.5f, // V�rtice inferior derecho
        0.5f,  0.5f, // V�rtice superior derecho
        -0.5f,  0.5f  // V�rtice superior izquierdo
    };

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, quad);
    glDrawArrays(GL_QUADS, 0, 4);
    glDisableClientState(GL_VERTEX_ARRAY);
    glFlush();
}
//array indexado
void Example7::DrawQuad3index()
{
    // Definir los v�rtices del quad (cuadrado)
    GLfloat vertices[] = {
        -0.5f, -0.5f, // V�rtice inferior izquierdo
         0.5f, -0.5f, // V�rtice inferior derecho
         0.5f,  0.5f, // V�rtice superior derecho
        -0.5f,  0.5f  // V�rtice superior izquierdo
    };

    // Definir los �ndices para los v�rtices (2 tri�ngulos que forman el quad)
    GLuint indices[] = {
        0, 1, 2,  // Primer tri�ngulo
        2, 3, 0   // Segundo tri�ngulo
    };

    // Habilitar el uso del Vertex Array
    glEnableClientState(GL_VERTEX_ARRAY);

    // Definir el puntero al array de v�rtices
    glVertexPointer(2, GL_FLOAT, 0, vertices);

    // Dibujar el quad usando los �ndices
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, indices);

    // Deshabilitar el uso del Vertex Array
    glDisableClientState(GL_VERTEX_ARRAY);

    glFlush();
}
//array indexado
void Example7::DrawSphere2(float radius, int slices, int stacks)
{
    std::vector<GLfloat> vertices;
    std::vector<GLuint> indices;

    // Generar los v�rtices de la esfera
    for (int stack = 0; stack <= stacks; ++stack) {
        float phi = M_PI * stack / stacks; // Coordenada en el eje vertical (latitud)
        float y = cos(phi);
        float r = sin(phi);

        for (int slice = 0; slice <= slices; ++slice) {
            float theta = 2.0f * M_PI * slice / slices; // Coordenada en el eje horizontal (longitud)
            float x = r * cos(theta);
            float z = r * sin(theta);

            // A�adir los v�rtices escalados por el radio
            vertices.push_back(x * radius);
            vertices.push_back(y * radius);
            vertices.push_back(z * radius);
        }
    }

    // Generar los �ndices para los tri�ngulos
    for (int stack = 0; stack < stacks; ++stack) {
        for (int slice = 0; slice < slices; ++slice) {
            int first = (stack * (slices + 1)) + slice;
            int second = first + slices + 1;

            // Primer tri�ngulo
            indices.push_back(first);
            indices.push_back(second);
            indices.push_back(first + 1);

            // Segundo tri�ngulo
            indices.push_back(second);
            indices.push_back(second + 1);
            indices.push_back(first + 1);
        }
    }

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices.data());
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, indices.data());
    glDisableClientState(GL_VERTEX_ARRAY);
    glFlush();
}
//array simple
void Example7::DrawSphereSimple(float radius, int slices, int stacks)
{
    std::vector<GLfloat> vertices;

    // Generar los v�rtices de la esfera
    for (int stack = 0; stack < stacks; ++stack) {
        float phi1 = M_PI * stack / stacks;           // Coordenada en el eje vertical (latitud)
        float phi2 = M_PI * (stack + 1) / stacks;     // Coordenada en el eje vertical de la siguiente stack

        float y1 = cos(phi1);
        float r1 = sin(phi1);
        float y2 = cos(phi2);
        float r2 = sin(phi2);

        for (int slice = 0; slice < slices; ++slice) {
            float theta1 = 2.0f * M_PI * slice / slices;             // Coordenada en el eje horizontal (longitud)
            float theta2 = 2.0f * M_PI * (slice + 1) / slices;       // Siguiente longitud

            // Coordenadas de los cuatro v�rtices para formar dos tri�ngulos
            float x1 = r1 * cos(theta1);
            float z1 = r1 * sin(theta1);
            float x2 = r1 * cos(theta2);
            float z2 = r1 * sin(theta2);
            float x3 = r2 * cos(theta1);
            float z3 = r2 * sin(theta1);
            float x4 = r2 * cos(theta2);
            float z4 = r2 * sin(theta2);

            // Primer tri�ngulo
            vertices.push_back(x1 * radius);
            vertices.push_back(y1 * radius);
            vertices.push_back(z1 * radius);

            vertices.push_back(x3 * radius);
            vertices.push_back(y2 * radius);
            vertices.push_back(z3 * radius);

            vertices.push_back(x4 * radius);
            vertices.push_back(y2 * radius);
            vertices.push_back(z4 * radius);

            // Segundo tri�ngulo
            vertices.push_back(x1 * radius);
            vertices.push_back(y1 * radius);
            vertices.push_back(z1 * radius);

            vertices.push_back(x4 * radius);
            vertices.push_back(y2 * radius);
            vertices.push_back(z4 * radius);

            vertices.push_back(x2 * radius);
            vertices.push_back(y1 * radius);
            vertices.push_back(z2 * radius);
        }
    }

    // Configuraci�n de los arreglos de v�rtices
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices.data());

    // Dibujo de los v�rtices como tri�ngulos
    glDrawArrays(GL_TRIANGLES, 0, vertices.size() / 3);

    glDisableClientState(GL_VERTEX_ARRAY);
    glFlush();
}
//array indexado
void Example7::DrawPyramid2()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Definir v�rtices de la pir�mide (base cuadrada con 4 v�rtices y un v�rtice superior)
    GLfloat vertices[] = {
        // Base (cuadrado)
        -0.5f, 0.0f, -0.5f,  // 0: V�rtice inferior izquierdo
         0.5f, 0.0f, -0.5f,  // 1: V�rtice inferior derecho
         0.5f, 0.0f,  0.5f,  // 2: V�rtice superior derecho
        -0.5f, 0.0f,  0.5f,  // 3: V�rtice superior izquierdo
        // V�rtice superior (punta de la pir�mide)
         0.0f, 1.0f,  0.0f   // 4: V�rtice superior
    };

    // Definir los �ndices para las caras de la pir�mide (4 caras triangulares y 1 base)
    GLuint indices[] = {
        // Cara frontal
        0, 1, 4,
        // Cara derecha
        1, 2, 4,
        // Cara trasera
        2, 3, 4,
        // Cara izquierda
        3, 0, 4,
        // Base (dos tri�ngulos)
        0, 1, 2,
        2, 3, 0
    };

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(GLuint), GL_UNSIGNED_INT, indices);
    glDisableClientState(GL_VERTEX_ARRAY);
    glFlush();
}
//array simple
void Example7::DrawPyramidSimple()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Definir v�rtices de la pir�mide directamente en el orden correcto (sin �ndices)
    GLfloat vertices[] = {
        // Cara frontal (tri�ngulo)
        -0.5f, 0.0f, -0.5f,  // V�rtice inferior izquierdo
         0.5f, 0.0f, -0.5f,  // V�rtice inferior derecho
         0.0f, 1.0f,  0.0f,  // V�rtice superior

        // Cara derecha (tri�ngulo)
         0.5f, 0.0f, -0.5f,  // V�rtice inferior derecho
         0.5f, 0.0f,  0.5f,  // V�rtice superior derecho
         0.0f, 1.0f,  0.0f,  // V�rtice superior

        // Cara trasera (tri�ngulo)
         0.5f, 0.0f,  0.5f,  // V�rtice superior derecho
        -0.5f, 0.0f,  0.5f,  // V�rtice superior izquierdo
         0.0f, 1.0f,  0.0f,  // V�rtice superior

        // Cara izquierda (tri�ngulo)
        -0.5f, 0.0f,  0.5f,  // V�rtice superior izquierdo
        -0.5f, 0.0f, -0.5f,  // V�rtice inferior izquierdo
         0.0f, 1.0f,  0.0f,  // V�rtice superior

        // Base (dos tri�ngulos)
        -0.5f, 0.0f, -0.5f,  // V�rtice inferior izquierdo
         0.5f, 0.0f, -0.5f,  // V�rtice inferior derecho
         0.5f, 0.0f,  0.5f,  // V�rtice superior derecho

         0.5f, 0.0f,  0.5f,  // V�rtice superior derecho
        -0.5f, 0.0f,  0.5f,  // V�rtice superior izquierdo
        -0.5f, 0.0f, -0.5f   // V�rtice inferior izquierdo
    };

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glDrawArrays(GL_TRIANGLES, 0, 18); // 18 v�rtices (6 tri�ngulos, cada uno con 3 v�rtices)
    glDisableClientState(GL_VERTEX_ARRAY);
    glFlush();
}
//array instanced

/*void Example7::DrawPiramidInstance(float instances)
{
    // V�rtices de la pir�mide (4 v�rtices de la base y 1 v�rtice superior)
    GLfloat vertices[] = {
        // Base (cuadrado)
        -0.5f, 0.0f, -0.5f,  // 0: V�rtice inferior izquierdo
         0.5f, 0.0f, -0.5f,  // 1: V�rtice inferior derecho
         0.5f, 0.0f,  0.5f,  // 2: V�rtice superior derecho
        -0.5f, 0.0f,  0.5f,  // 3: V�rtice superior izquierdo
        // V�rtice superior (punta de la pir�mide)
         0.0f, 1.0f,  0.0f   // 4: V�rtice superior
    };

    // �ndices para definir las caras de la pir�mide
    GLuint indices[] = {
        // Cara frontal
        0, 1, 4,
        // Cara derecha
        1, 2, 4,
        // Cara trasera
        2, 3, 4,
        // Cara izquierda
        3, 0, 4,
        // Base (dos tri�ngulos)
        0, 1, 2,
        2, 3, 0
    };
    glEnableClientState(GL_VERTEX_ARRAY);

    // Especificar el puntero al array de v�rtices
    glVertexPointer(3, GL_FLOAT, 0, vertices);

    // Dibujar la pir�mide utilizando instancias
    glDrawElementsInstanced(GL_TRIANGLES, sizeof(indices) / sizeof(GLuint), GL_UNSIGNED_INT, indices, instances);

    // Deshabilitar el uso de arrays de v�rtices
    glDisableClientState(GL_VERTEX_ARRAY);
    glutSwapBuffers();

}
*/

void Example7::KeyboardFunc(unsigned char key, int X, int Y)
{

}
void Example7::Idle() 
{
}

