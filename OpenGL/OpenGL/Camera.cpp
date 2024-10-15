#include "Camera.h"
#include "IncludeGL.h"
#include <cmath>

Camera::Camera() : speed(0.1f), sensitivity(0.05f)
{
}

void Camera::SetPosition(Vector3 _position)
{
    position = _position;
}

Vector3 Camera::GetPosition()
{
    return position;
}

void Camera::Init()
{
    position = Vector3(5, 0, 5); 
    forward = Vector3(0, 0, -1); 
    up = Vector3(0, 1, 0);        
}

void Camera::Update()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity(); 

    Vector3 target = position + forward;
    gluLookAt(position.x, position.y, position.z,
        target.x, target.y, target.z,
        up.x, up.y, up.z);
}

void Camera::LookAt(Vector3 target, float distance)
{
    // Calcula la dirección hacia el cubo
    forward = (target - position).Normalize();

    // Reposiciona la cámara a una distancia fija
    position = target - forward * distance;

    Update();
}

void Camera::MoveForward()
{
    position = position + forward * speed;
}

void Camera::MoveBackward()
{
    position = position - forward * speed;
}

void Camera::StrafeLeft()
{
    Vector3 right = forward.Cross(up).Normalize();
    position = position - right * speed;
}

void Camera::StrafeRight()
{
    Vector3 right = forward.Cross(up).Normalize();
    position = position + right * speed;
}

void Camera::Rotate(float angleX, float angleY)
{
    // Rotación horizontal (Yaw)
    float yaw = angleX * sensitivity;
    forward.x = cos(yaw) * forward.x - sin(yaw) * forward.z;
    forward.z = sin(yaw) * forward.x + cos(yaw) * forward.z;

    // Rotación vertical (Pitch)
    float pitch = angleY * sensitivity;
    forward.y += pitch;
    forward.Normalize();
}