//
// Created by redeb on 05.12.2023.
//

#ifndef TUCANCORE_VECTOR3_H
#define TUCANCORE_VECTOR3_H

#include <array>
#include <limits>

template<class T>
struct Vector3 final {
private:
    std::array<T, 3> m_components{};

public:
    Vector3() = default;
    Vector3(const T& x, const T& y, const T& z);
    Vector3(const Vector3& other);

    explicit Vector3(const T& factor);

    T getX() const;
    T getY() const;
    T getZ() const;

    void setX(const T& x);
    void setY(const T& y);
    void setZ(const T& z);

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

    bool operator==(const Vector3& other) const;
    bool operator!=(const Vector3& other) const;

    T dot(const Vector3& other) const;
    Vector3<T> cross(const Vector3& other) const;
};


#endif
