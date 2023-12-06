//
// Created by redeb on 06.12.2023.
//

#ifndef TUCANCORE_MATRIX4X4_H
#define TUCANCORE_MATRIX4X4_H

#include <array>
#include "Vector3.h"

template<class T>
struct Matrix4x4 final {
private:
    std::array<std::array<T, 4>, 4> m_m{};

public:
    Matrix4x4() = default;
    Matrix4x4(const T& m11, const T& m12, const T& m13, const T& m14,
              const T& m21, const T& m22, const T& m23, const T& m24,
              const T& m31, const T& m32, const T& m33, const T& m34,
              const T& m41, const T& m42, const T& m43, const T& m44);

    explicit Matrix4x4(const std::array<std::array<T, 4>, 4>& m);

    T m11() const;
    T m12() const;
    T m13() const;
    T m14() const;

    T m21() const;
    T m22() const;
    T m23() const;
    T m24() const;

    T m31() const;
    T m32() const;
    T m33() const;
    T m34() const;

    T m41() const;
    T m42() const;
    T m43() const;
    T m44() const;

    void m11(const T& m11);
    void m12(const T& m12);
    void m13(const T& m13);
    void m14(const T& m14);

    void m21(const T& m21);
    void m22(const T& m22);
    void m23(const T& m23);
    void m24(const T& m24);

    void m31(const T& m31);
    void m32(const T& m32);
    void m33(const T& m33);
    void m34(const T& m34);

    void m41(const T& m41);
    void m42(const T& m42);
    void m43(const T& m43);
    void m44(const T& m44);

    Matrix4x4<T>& operator=(const Matrix4x4& other) = default;
    Matrix4x4<T> operator*(const Matrix4x4& other) const;

    Vector3<T> mulPt(const Vector3<T>& pt) const;
    Vector3<T> mulPt3x4(const Vector3<T>& pt) const;
    Vector3<T> mulVec(const Vector3<T>& vec) const;
};


#endif //TUCANCORE_MATRIX4X4_H
