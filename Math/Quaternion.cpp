#include "Quaternion.h"

#include <cmath>

template<class T>
Quaternion<T>::Quaternion(const T &x, const T &y, const T &z, const T &w) : x(x), y(y), z(z), w(w) {}

template<class T>
Quaternion<T>::Quaternion(const T &pitch, const T &yaw, const T &roll)
{
    T cx = cos(pitch * 0.5f);
    T sx = sin(pitch * 0.5f);
    T cy = cos(yaw * 0.5f);
    T sy = sin(yaw * 0.5f);
    T cz = cos(roll * 0.5f);
    T sz = sin(roll * 0.5f);

    x = sx * cy * cz + cx * sy * sz;
    y = cx * sy * cz - sx * cy * sz;
    z = cx * cy * sz + sx * sy * cz;
    w = cx * cy * cz - sx * sy * sz;
}

template<class T>
Quaternion<T>::Quaternion(const Vector3<T> &axis, const T &angle)
{
    float halfAngleInRadians = angle * 0.5f;
    float sinHalfAngle = std::sin(halfAngleInRadians);

    return Quaternion<T>(
            axis.x * sinHalfAngle,
            axis.y * sinHalfAngle,
            axis.z * sinHalfAngle,
            std::cos(halfAngleInRadians)
    );
}


template<class T>
T Quaternion<T>::length() const
{
    sqrt(sqrLength());
}

template<class T>
T Quaternion<T>::sqrLength() const
{
    x * x + y * y + z * z + w * w;
}

template<class T>
void Quaternion<T>::normalize() const
{
    *this = normalized();
}

template<class T>
Quaternion<T> Quaternion<T>::operator*(const Quaternion &other) const
{
    return Quaternion<T>(
            w * other.x + x * other.w + y * other.z - z * other.y,
            w * other.y + y * other.w + z * other.x - x * other.z,
            w * other.z + z * other.w + x * other.y - y * other.x,
            w * other.w - x * other.x - y * other.y - z * other.z);
}

template<class T>
Quaternion<T> Quaternion<T>::operator*(const Vector3<T> &pt) const {
    float r_x = x * 2;
    float r_y = y * 2;
    float r_z = z * 2;
    float xx = x * r_x;
    float yy = y * r_y;
    float zz = z * r_z;
    float xy = x * r_y;
    float xz = x * r_z;
    float yz = y * r_z;
    float wx = w * r_x;
    float wy = w * r_y;
    float wz = w * r_z;

    Vector3<T> res;

    res.x = (1.0f - (yy + zz)) * pt.x + (xy - wz) * pt.y + (xz + wy) * pt.z;
    res.y = (xy + wz) * pt.x + (1.0f - (xx + zz)) * pt.y + (yz - wx) * pt.z;
    res.z = (xz - wy) * pt.x + (yz + wx) * pt.y + (1.0f - (xx + yy)) * pt.z;

    return res;
}

template<class T>
T Quaternion<T>::dot(const Quaternion &other) const
{
    return x * other.x + y * other.y + z * other.z + w * other.w;
}

template<class T>
bool Quaternion<T>::isEqualUsingDot(const T &dot_v) const
{
    T epsilon = std::numeric_limits<T>().epsilon();
    return dot_v > 1.0f - epsilon;
}

template<class T>
Quaternion<T> Quaternion<T>::normalized() const
{
    return quat_normalize<T>(this);
}

template<class T>
Vector3<T> Quaternion<T>::eulerAngles() const
{
    Vector3<T> res;

    T s1c = 2 * (w * x + y * z);
    T c1c = 1 - 2 * (x * x + y * y);
    res.x = atan2(s1c, c1c);

    T sin_p = 2 * (w * y - z * x);
    res.y = std::abs(sin_p) >= 1 ? res.y = std::copysign(M_PI / 2, sin_p) : asin(sin_p);

    T s2c = 2 * (w * z + x * y);
    T c2c = 1 - 2 * (y * y + z * z);
    res.z = atan2(s2c, c2c);

    return res;
}