#pragma once
#include <string>
class Figura
{
protected:
	std::string nameF;
	int width;
	float color[3];
	int IDtexture;
public:
	Figura(const std::string& name, int w, float r, float g, float b);
	Figura();
	virtual void init() = 0;
	virtual void Draw() = 0;
};
