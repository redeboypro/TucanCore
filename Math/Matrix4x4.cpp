#include "Matrix4x4.h"

template<class T>
Matrix4x4<T>::Matrix4x4(const std::array<std::array<T, 4>, 4> &m) : m_m(m) {}

template<class T>
Matrix4x4<T>::Matrix4x4(const T &m11, const T &m12, const T &m13, const T &m14,
                        const T &m21, const T &m22, const T &m23, const T &m24,
                        const T &m31, const T &m32, const T &m33, const T &m34,
                        const T &m41, const T &m42, const T &m43, const T &m44) :
        m_m({m11, m12, m13, m14,
             m21, m22, m23, m24,
             m31, m32, m33, m34,
             m41, m42, m43, m44}) {}

template<class T>
T Matrix4x4<T>::m11() const
{
    return m_m[0][0];
}

template<class T>
T Matrix4x4<T>::m12() const
{
    return m_m[0][1];
}

template<class T>
T Matrix4x4<T>::m13() const
{
    return m_m[0][2];
}

template<class T>
T Matrix4x4<T>::m14() const
{
    return m_m[0][3];
}

template<class T>
T Matrix4x4<T>::m21() const
{
    return m_m[1][0];
}

template<class T>
T Matrix4x4<T>::m22() const
{
    return m_m[1][1];
}

template<class T>
T Matrix4x4<T>::m23() const
{
    return m_m[1][2];
}

template<class T>
T Matrix4x4<T>::m24() const
{
    return m_m[1][3];
}

template<class T>
T Matrix4x4<T>::m31() const
{
    return m_m[2][0];
}

template<class T>
T Matrix4x4<T>::m32() const
{
    return m_m[2][1];
}

template<class T>
T Matrix4x4<T>::m33() const
{
    return m_m[2][2];
}

template<class T>
T Matrix4x4<T>::m34() const
{
    return m_m[2][3];
}

template<class T>
T Matrix4x4<T>::m41() const
{
    return m_m[3][0];
}

template<class T>
T Matrix4x4<T>::m42() const
{
    return m_m[3][1];
}

template<class T>
T Matrix4x4<T>::m43() const
{
    return m_m[3][2];
}

template<class T>
T Matrix4x4<T>::m44() const
{
    return m_m[3][3];
}

template<class T>
void Matrix4x4<T>::m11(const T &m11)
{
    m_m[0][0] = m11;
}

template<class T>
void Matrix4x4<T>::m12(const T &m12)
{
    m_m[0][1] = m12;
}

template<class T>
void Matrix4x4<T>::m13(const T &m13)
{
    m_m[0][2] = m13;
}

template<class T>
void Matrix4x4<T>::m14(const T &m14)
{
    m_m[0][3] = m14;
}

template<class T>
void Matrix4x4<T>::m21(const T &m21)
{
    m_m[1][0] = m21;
}

template<class T>
void Matrix4x4<T>::m22(const T &m22)
{
    m_m[1][1] = m22;
}

template<class T>
void Matrix4x4<T>::m23(const T &m23)
{
    m_m[1][2] = m23;
}

template<class T>
void Matrix4x4<T>::m24(const T &m24)
{
    m_m[1][3] = m24;
}

template<class T>
void Matrix4x4<T>::m31(const T &m31)
{
    m_m[2][0] = m31;
}

template<class T>
void Matrix4x4<T>::m32(const T &m32)
{
    m_m[2][1] = m32;
}

template<class T>
void Matrix4x4<T>::m33(const T &m33)
{
    m_m[2][2] = m33;
}

template<class T>
void Matrix4x4<T>::m34(const T &m34)
{
    m_m[2][3] = m34;
}

template<class T>
void Matrix4x4<T>::m41(const T &m41)
{
    m_m[3][0] = m41;
}

template<class T>
void Matrix4x4<T>::m42(const T &m42)
{
    m_m[3][1] = m42;
}

template<class T>
void Matrix4x4<T>::m43(const T &m43)
{
    m_m[3][2] = m43;
}

template<class T>
void Matrix4x4<T>::m44(const T &m44)
{
    m_m[3][3] = m44;
}

template<class T>
Matrix4x4<T> Matrix4x4<T>::operator*(const Matrix4x4 &other) const
{
    Matrix4x4 matrix;
    for (int c = 0; c < 4; c++)
    {
        for (int r = 0; r < 4; r++)
        {
            matrix.m[r][c] = m_m.m[r][0] * other.m_m[0][c] +
                             m_m.m[r][1] * other.m_m[1][c] +
                             m_m.m[r][2] * other.m_m[2][c] +
                             m_m.m[r][3] * other.m_m[3][c];
        }
    }
    return matrix;
}

template<class T>
Vector3<T> Matrix4x4<T>::mulPt(const Vector3<T> &pt) const
{
    Vector3<T> res = mulPt3x4(pt);

    float w = m41() * pt.getX() + m42() * pt.getY() + m43() * pt.getZ() + m44();

    w = 1.0f / w;
    res *= w;

    return res;
}

template<class T>
Vector3<T> Matrix4x4<T>::mulPt3x4(const Vector3<T> &pt) const
{
    Vector3<T> res;

    res.x = m11() * pt.getX() + m12() * pt.getY() + m13() * pt.getZ() + m14();
    res.y = m21() * pt.getX() + m22() * pt.getY() + m23() * pt.getZ() + m24();
    res.z = m31() * pt.getX() + m32() * pt.getY() + m33() * pt.getZ() + m34();

    return res;
}

template<class T>
Vector3<T> Matrix4x4<T>::mulVec(const Vector3<T> &vec) const
{
    Vector3<T> res;

    res.x = m11() * vec.getX() + m12() * vec.getY() + m13() * vec.getZ();
    res.y = m21() * vec.getX() + m22() * vec.getY() + m23() * vec.getZ();
    res.z = m31() * vec.getX() + m32() * vec.getY() + m33() * vec.getZ();

    return res;
}


