#pragma once
#include "IncludeGL.h"
#include <iostream>
class Lights
{
public:

	Lights();

	virtual void init();
	//virtual void properties(GLfloat [] ambientLight );
	void SetPosition(GLenum lightID, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
	void properties(GLfloat ambientLight[], GLfloat diffuse_light[], GLfloat specular_light[], GLfloat light_position[]);
	//virtual void


};

