#include "Vector4.h"

template<class T>
Vector4<T>::Vector4(const T &factor) : x(factor), y(factor), z(factor), w(factor) {}

template<class T>
Vector4<T>::Vector4(const T &x, const T &y, const T &z, const T &w) : x(x), y(y), z(z), w(w) {}

template<class T>
Vector4<T>::Vector4(const Vector4 &other) : x(other.x), y(other.y), z(other.z), w(other.w) {}

template<class T>
Vector4<T>::Vector4(const Vector3<T> &other, const T &w) : x(other.x), y(other.y), z(other.z), w(w) {}

template<class T>
Vector3<T> Vector4<T>::getXyz() const
{
    return Vector3<T>(x, y, z);
}

template<class T>
Vector4<T> Vector4<T>::operator+(const Vector4 &other) const
{
    return Vector4<T>(x + other.x, y + other.y, z + other.z, w + other.w);
}

template<class T>
Vector4<T> Vector4<T>::operator-() const
{
    return Vector4<T>(-x, -y, -z, -w);
}

template<class T>
Vector4<T> Vector4<T>::operator-(const Vector4 &other) const
{
    return Vector4<T>(x - other.x, y - other.y, z - other.z, w - other.w);
}

template<class T>
Vector4<T> Vector4<T>::operator*(const Vector4 &other) const
{
    return Vector4<T>(x * other.x, y * other.y, z * other.z, w * other.w);
}

template<class T>
Vector4<T> Vector4<T>::operator*(const T& factor) const
{
    return Vector4<T>(x * factor, y * factor, z * factor, w * factor);
}

template<class T>
Vector4<T> Vector4<T>::operator/(const Vector4 &other) const
{
    return Vector4<T>(x / other.x, y / other.y, z / other.z, w / other.w);
}

template<class T>
Vector4<T> Vector4<T>::operator/(const T& factor) const
{
    float invertedFactor = 1.0f / factor;
    return Vector4<T>(x * invertedFactor, y * invertedFactor, z * invertedFactor, w * invertedFactor);
}

template<class T>
T Vector4<T>::length() const
{
    sqrt(sqrLength());
}

template<class T>
T Vector4<T>::sqrLength() const
{
    x * x + y * y + z * z + w * w;
}

template<class T>
void Vector4<T>::normalize() const
{
    T invertedFactor = 1.0f / length();

    x *= invertedFactor;
    y *= invertedFactor;
    z *= invertedFactor;
    w *= invertedFactor;
}

template<class T>
T Vector4<T>::dot(const Vector4 &other) const
{
    return x * other.x + y * other.y + z * other.z + w * other.w;
}

template<class T>
Vector4<T> Vector4<T>::cross(const Vector4 &other) const
{
    return Vector4<T>(getXyz().cross(other.getXyz()), 0);
}
