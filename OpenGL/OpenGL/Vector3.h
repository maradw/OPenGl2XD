#pragma once
#include <cmath>

class Vector3
{
public:
    float x, y, z;

    Vector3() : x(0), y(0), z(0) {}
    Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

    // Producto cruzado
    Vector3 Cross(const Vector3& other) const
    {
        return Vector3(
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x
        );
    }

    // Normalizar vector
    Vector3 Normalize() const
    {
        float length = sqrt(x * x + y * y + z * z);
        if (length == 0) return Vector3(0, 0, 0);
        return Vector3(x / length, y / length, z / length);
    }

    // Sobrecarga de operadores para sumar, restar y multiplicar por un escalar
    Vector3 operator+(const Vector3& other) const
    {
        return Vector3(x + other.x, y + other.y, z + other.z);
    }

    Vector3 operator-(const Vector3& other) const
    {
        return Vector3(x - other.x, y - other.y, z - other.z);
    }

    Vector3 operator*(float scalar) const
    {
        return Vector3(x * scalar, y * scalar, z * scalar);
    }
};