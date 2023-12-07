#include "Vector3.h"

template<class T>
Vector3<T>::Vector3(const T &factor) : x(factor), y(factor), z(factor) {}

template<class T>
Vector3<T>::Vector3(const T& x, const T& y, const T& z) : x(x), y(y), z(z) {}

template<class T>
Vector3<T>::Vector3(const Vector3 &other) : x(other.x), y(other.y), z(other.z) {}

template<class T>
Vector3<T> Vector3<T>::operator+(const Vector3 &other) const
{
    return Vector3<T>(x + other.x, y + other.y, z + other.z);
}

template<class T>
Vector3<T> Vector3<T>::operator-() const
{
    return Vector3<T>(-x, -y, -z);
}

template<class T>
Vector3<T> Vector3<T>::operator-(const Vector3 &other) const
{
    return Vector3<T>(x - other.x, y - other.y, z - other.z);
}

template<class T>
Vector3<T> Vector3<T>::operator*(const Vector3 &other) const
{
    return Vector3<T>(x * other.x, y * other.y, z * other.z);
}

template<class T>
Vector3<T> Vector3<T>::operator*(float factor) const
{
    return Vector3<T>(x * factor, y * factor, z * factor);
}

template<class T>
Vector3<T> Vector3<T>::operator/(const Vector3 &other) const
{
    return Vector3<T>(x / other.x, y / other.y, z / other.z);
}

template<class T>
Vector3<T> Vector3<T>::operator/(float factor) const
{
    float invertedFactor = 1.0f / factor;
    return Vector3<T>(x * invertedFactor, y * invertedFactor, z * invertedFactor);
}

template<class T>
T Vector3<T>::length() const
{
    sqrt(sqrLength());
}

template<class T>
T Vector3<T>::sqrLength() const
{
    x * x + y * y + z * z;
}

template<class T>
void Vector3<T>::normalize() const
{
    float invertedFactor = 1.0f / length();

    x *= invertedFactor;
    y *= invertedFactor;
    z *= invertedFactor;
}

template<class T>
T Vector3<T>::dot(const Vector3 &other) const
{
    return x * other.x + y * other.y + z * other.z;
}

template<class T>
Vector3<T> Vector3<T>::cross(const Vector3 &other) const
{
    return Vector3(
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x
    );
}






