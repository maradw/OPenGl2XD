#pragma once
#include "Example.h"
class Example1: public Example
{
public:
	Example1();
	
	virtual void init()override;
	virtual void Render()override;
	void DrawPolyhedron();
	void DrawTorus();
	void DrawFrustum();
	void DrawCone();
	void DrawCylinder();
	void DrawSphere();
	void DrawParallelepiped();
	void DrawOrthohedron();
	void DrawPrism();
	void DrawTruncatedPyramid();
	void DrawPiramid();
	void DrawDodecahedron();
	void DrawOctahedron();
	void DrawIcosahedron();
	void DrawTetrahedron();
	void DrawCube();
	virtual void KeyboardFunc(unsigned char key, int X, int Y)override;
	void Figures(unsigned char key);
	virtual void Idle()override;

	void DrawPoint();
	void DrawLineChain();
	void XY();
	void XYZ();
	void Grid();
	void DrawLine();
	void DrawColoredLine();
};

