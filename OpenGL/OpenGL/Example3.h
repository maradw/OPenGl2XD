#pragma once
#include "Example.h"
#include "Camera.h"
#include "Polígono.h"

class Example3 : public Example
{
    Camera* camera;
    Polígono* polygon;
    Vector3 objectPosition;
public:
    Example3();
    virtual void init() override;
    virtual void Render() override;
    virtual void KeyboardFunc(unsigned char key, int X, int Y) override;
    virtual void TPSKeyboardFunc(unsigned char key, int x, int y); // Teclas especiales (flechas)
    virtual void Idle() override;

    void MoveObject(int dx, int dz);
};

