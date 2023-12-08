#ifndef TUCANCORE_QUATERNION_H
#define TUCANCORE_QUATERNION_H

#include <array>
#include "MathF.h"
#include "Vector3.h"

template<class T>
struct Quaternion final : Vector<T, 4> {

public:
    Quaternion() = default;
    Quaternion(const T& x, const T& y, const T& z, const T& w);
    Quaternion(const T& pitch, const T& yaw, const T& roll);
    Quaternion(const Vector3<T>& axis, const T& angle);

    float& x = this->m_components[0];
    float& y = this->m_components[1];
    float& z = this->m_components[2];
    float& w = this->m_components[3];

    T length() const;
    T sqrLength() const;
    void normalize() const;
    Quaternion<T> normalized() const;

    Vector3<T> eulerAngles() const;

    Quaternion<T>& operator=(const Quaternion& other) = default;
    Quaternion<T> operator*(const Quaternion<T>& other) const;
    Quaternion<T> operator*(const Vector3<T>& pt) const;

    T dot(const Quaternion& other) const;
    bool isEqualUsingDot(const T& dot_v) const;
};


#endif
