#include "Matrix4x4.h"

template<class T>
Matrix4x4<T>::Matrix4x4(const Vector<T, 4> *rows)
{
    for (int i = 0; i < 4; i++)
    {
        this[i] = rows[i];
    }
}

template<class T>
Matrix4x4<T>::Matrix4x4(const T &m11, const T &m12, const T &m13, const T &m14,
                        const T &m21, const T &m22, const T &m23, const T &m24,
                        const T &m31, const T &m32, const T &m33, const T &m34,
                        const T &m41, const T &m42, const T &m43, const T &m44)
{
    this[0][0] = m11;
    this[0][1] = m12;
    this[0][2] = m13;
    this[0][3] = m14;

    this[1][0] = m21;
    this[1][1] = m22;
    this[1][2] = m23;
    this[1][3] = m24;

    this[2][0] = m31;
    this[2][1] = m32;
    this[2][2] = m33;
    this[2][3] = m34;

    this[3][0] = m41;
    this[3][1] = m42;
    this[3][2] = m43;
    this[3][3] = m44;
}

template<class T>
Matrix4x4<T> Matrix4x4<T>::operator*(const Matrix4x4 &other) const
{
    Matrix4x4 matrix;
    for (int c = 0; c < 4; c++)
    {
        for (int r = 0; r < 4; r++)
        {
            matrix.m[r][c] = this[r][0] * other[0][c] +
                             this[r][1] * other[1][c] +
                             this[r][2] * other[2][c] +
                             this[r][3] * other[3][c];
        }
    }
    return matrix;
}

template<class T>
Vector3<T> Matrix4x4<T>::mulPt(const Vector3<T> &pt) const
{
    Vector3<T> res = mulPt3x4(pt);

    float w = this[3][0] * pt.getX() + this[3][1] * pt.getY() + this[3][2] * pt.getZ() + this[3][3];

    w = 1.0f / w;
    res *= w;

    return res;
}

template<class T>
Vector3<T> Matrix4x4<T>::mulPt3x4(const Vector3<T> &pt) const
{
    Vector3<T> res;

    res.x = this[0][0] * pt.x + this[0][1] * pt.y + this[0][2] * pt.z + this[0][3];
    res.y = this[1][0] * pt.x + this[1][1] * pt.y + this[1][2] * pt.z + this[1][3];
    res.z = this[2][0] * pt.x + this[2][1] * pt.y + this[2][2] * pt.z + this[2][3];

    return res;
}

template<class T>
Vector3<T> Matrix4x4<T>::mulVec(const Vector3<T> &vec) const
{
    Vector3<T> res;

    res.x = this[0][0] * vec.x + this[0][1] * vec.y + this[0][2] * vec.z;
    res.y = this[1][0] * vec.x + this[1][1] * vec.y + this[1][2] * vec.z;
    res.z = this[2][0] * vec.x + this[2][1] * vec.y + this[2][2] * vec.z;

    return res;
}



