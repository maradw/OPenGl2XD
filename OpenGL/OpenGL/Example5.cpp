#include "Example5.h"
//#include "Color.h"
#include "Cubo.h"
#include "Esfera.h"
#include "Triangulo.h"
#include <stdio.h>
#include "BMPTextureLoader.h"
Example5::Example5()
{
}
void Example5::init()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0);
	gluLookAt(5, 5, 5, 0, 0, 0, 0, 1, 0);
	glMatrixMode(GL_MODELVIEW);

	cubo = new Cubo();
	_TextureLoader = new BMPTextureLoader();
	texture = ((BMPTextureLoader*)_TextureLoader)->LoadBMP("./textures/wallBMP.bmp");

	esfera = new Esfera();
	_TextureLoader1 = new BMPTextureLoader();
	texture1 = ((BMPTextureLoader*)_TextureLoader1)->LoadBMP("./textures/ground.bmp");

	cuadrado = new Cuadrado();
	_TextureLoader2 = new BMPTextureLoader();
	texture2 = ((BMPTextureLoader*)_TextureLoader2)->LoadBMP("./textures/stone.bmp");

	triangulo = new Triangulo();
	_TextureLoader3 = new BMPTextureLoader();
	texture3 = ((BMPTextureLoader*)_TextureLoader3)->LoadBMP("./textures/water.bmp");


}
void Example5::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	Example::DrawGrids(1);
	DrawShape();
	glFlush();
}
void Example5::KeyboardFunc(unsigned char key, int X, int Y)
{
	switch (key)
	{
	case 'A':
		pos.x += 0.5;
		break;
	case 'D':
		pos.x -= 0.5;
		break;
	case 'W':
		pos.z += 0.5;
		break;
	case 'S':
		pos.z -= 0.5;
		break;
	case 'Q':
		pos.y += 0.5;
		break;
	case 'E':
		pos.y -= 0.5;
		break;
	default:
		break;
	}
}
void Example5::Idle()
{

}
void Example5::DrawShape()
{
	
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

	// Dibujar cubo
	glBindTexture(GL_TEXTURE_2D, texture);

	glPushMatrix();
	glTranslatef(pos.x, pos.y, pos.z);
	cubo->Draw();
	glPopMatrix();

	// Dibujar esfera
	glBindTexture(GL_TEXTURE_2D, texture1);

	glPushMatrix();
	glTranslatef(0, 0, 0);
	esfera->Draw();
	glPopMatrix();

	//Dibujar triangulo
	glBindTexture(GL_TEXTURE_2D, texture2);

	glPushMatrix();
	glTranslatef(0, 0, 0);
	triangulo->Draw();
	glPopMatrix();

	//Dibujar cuadrado
	glBindTexture(GL_TEXTURE_2D, texture3);

	glPushMatrix();
	glTranslatef(0, 0, 0);
	cuadrado->Draw();
	glPopMatrix();

	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);
	glDisable(GL_TEXTURE_2D);

	glutSwapBuffers();
}
