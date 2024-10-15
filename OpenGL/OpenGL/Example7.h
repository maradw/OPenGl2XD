#pragma once
#include "Example.h"
class Example7 :
    public Example
{
public:
	Example7();
	virtual void init()override;
	virtual void Render()override;
	void DrawQuad2();
	virtual void KeyboardFunc(unsigned char key, int X, int Y)override;
	virtual void Idle()override;
	void DrawCube2();
};

