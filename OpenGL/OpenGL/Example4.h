/*#pragma once
#include "Example.h"
class Example4 : public Example
{
public:
	Example4();

	virtual void init()override;

	void Lights();

	virtual void Render()override;
	virtual void KeyboardFunc(unsigned char key, int X, int Y)override;
	void Figures(unsigned char key);
	virtual void Idle()override;
	void DrawCube();
	void DrawSphere();
};*/
#pragma once
#include "Example.h"
class Example4 :
public Example
{
public:
	Example4();
	virtual void init()override;
	virtual void Render()override;

	virtual void KeyboardFunc(unsigned char key, int X, int Y)override;
	virtual void Idle()override;
	void SetMaterial();
	void ConfigurarLuzDireccional();
	void SetPointLight();
	void ConfigurarLuzSpotLight();
	void DrawPlane();

};

