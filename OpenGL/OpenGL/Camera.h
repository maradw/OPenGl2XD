#pragma once
#include "Vector3.h"

class Camera
{
private:
    Vector3 position;    // Posición de la cámara
    Vector3 forward;     // Dirección a la que apunta la cámara
    Vector3 up;          // Vector "up" para la orientación de la cámara
    float speed;         // Velocidad de movimiento
    float sensitivity;   // Sensibilidad para rotaciones
public:
    Camera();
    void SetPosition(Vector3);
    Vector3 GetPosition();
    void Init();
    void Update();
    void LookAt(Vector3 target, float distance);
    void MoveForward();
    void MoveBackward();
    void StrafeLeft();
    void StrafeRight();
    void Rotate(float angleX, float angleY);
};