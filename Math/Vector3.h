//
// Created by redeb on 05.12.2023.
//

#ifndef TUCANCORE_VECTOR3_H
#define TUCANCORE_VECTOR3_H

#include <array>
#include <limits>
#include "Vector.h"

template<class T>
struct Vector3 final : Vector<T, 3> {
public:
    Vector3() = default;
    Vector3(const T& x, const T& y, const T& z);
    Vector3(const Vector3& other);

    explicit Vector3(const T& factor);

    float& x = this->m_components[0];
    float& y = this->m_components[1];
    float& z = this->m_components[2];

    T length() const;
    T sqrLength() const;
    void normalize() const;

    Vector3<T>& operator=(const Vector3& other) = default;
    Vector3<T> operator+(const Vector3& other) const;
    Vector3<T> operator-() const;
    Vector3<T> operator-(const Vector3& other) const;
    Vector3<T> operator*(const Vector3& other) const;
    Vector3<T> operator*(float factor) const;
    Vector3<T> operator/(const Vector3& other) const;
    Vector3<T> operator/(float factor) const;

    T dot(const Vector3& other) const;
    Vector3<T> cross(const Vector3& other) const;
};


#endif
