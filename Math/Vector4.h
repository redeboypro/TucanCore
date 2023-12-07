#ifndef TUCANCORE_VECTOR4_H
#define TUCANCORE_VECTOR4_H

#include <array>
#include "Vector3.h"

template<class T>
struct Vector4 : Vector<T, 4> {
public:
    Vector4() = default;
    Vector4(const T& x, const T& y, const T& z, const T& w);
    Vector4(const Vector4& other);
    Vector4(const Vector3<T>& other, const T& w);

    explicit Vector4(const T& factor);

    float& x = this->m_components[0];
    float& y = this->m_components[1];
    float& z = this->m_components[2];
    float& w = this->m_components[3];

    Vector3<T> getXyz() const;

    T length() const;
    T sqrLength() const;
    void normalize() const;

    Vector4<T>& operator=(const Vector4& other) = default;
    Vector4<T> operator+(const Vector4& other) const;
    Vector4<T> operator-() const;
    Vector4<T> operator-(const Vector4& other) const;
    Vector4<T> operator*(const Vector4& other) const;
    Vector4<T> operator*(float factor) const;
    Vector4<T> operator/(const Vector4& other) const;
    Vector4<T> operator/(float factor) const;

    T dot(const Vector4& other) const;
    Vector4<T> cross(const Vector4& other) const;
};


#endif
