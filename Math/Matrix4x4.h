//
// Created by redeb on 06.12.2023.
//

#ifndef TUCANCORE_MATRIX4X4_H
#define TUCANCORE_MATRIX4X4_H

#include <array>
#include "Vector3.h"
#include "Matrix.h"

template<class T>
struct Matrix4x4 final : Matrix<T, 4, 4> {
public:
    Matrix4x4() = default;
    Matrix4x4(const T& m11, const T& m12, const T& m13, const T& m14,
              const T& m21, const T& m22, const T& m23, const T& m24,
              const T& m31, const T& m32, const T& m33, const T& m34,
              const T& m41, const T& m42, const T& m43, const T& m44);

    explicit Matrix4x4(const std::array<Vector<T, 4>, 4>& rows);

    Matrix4x4<T>& operator=(const Matrix4x4& other) = default;
    Matrix4x4<T> operator*(const Matrix4x4& other) const;

    Vector3<T> mulPt(const Vector3<T>& pt) const;
    Vector3<T> mulPt3x4(const Vector3<T>& pt) const;
    Vector3<T> mulVec(const Vector3<T>& vec) const;
};


#endif
