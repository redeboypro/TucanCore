#include "Vector3.h"

template<class T>
Vector3<T>::Vector3(const T &factor) : m_components({factor, factor, factor}) {}

template<class T>
Vector3<T>::Vector3(const T& x, const T& y, const T& z) : m_components({x, y, z}) {}

template<class T>
Vector3<T>::Vector3(const Vector3 &other) : m_components({other.m_components}) {}

template<class T>
T Vector3<T>::getX() const
{
    return m_components[0];
}

template<class T>
T Vector3<T>::getY() const
{
    return m_components[1];
}

template<class T>
T Vector3<T>::getZ() const
{
    return m_components[2];
}

template<class T>
void Vector3<T>::setX(const T& x)
{
    m_components[0] = x;
}

template<class T>
void Vector3<T>::setY(const T& y)
{
    m_components[1] = y;
}

template<class T>
void Vector3<T>::setZ(const T& z)
{
    m_components[2] = z;
}

template<class T>
Vector3<T> Vector3<T>::operator+(const Vector3 &other) const
{
    return Vector3<T>(getX() + other.getX(), getY() + other.getY(), getZ() + other.getZ());
}

template<class T>
Vector3<T> Vector3<T>::operator-() const
{
    return Vector3<T>(-getX(), -getY(), -getZ());
}

template<class T>
Vector3<T> Vector3<T>::operator-(const Vector3 &other) const
{
    return Vector3<T>(getX() - other.getX(), getY() - other.getY(), getZ() - other.getZ());
}

template<class T>
Vector3<T> Vector3<T>::operator*(const Vector3 &other) const
{
    return Vector3<T>(getX() * other.getX(), getY() * other.getY(), getZ() * other.getZ());
}

template<class T>
Vector3<T> Vector3<T>::operator*(float factor) const
{
    return Vector3<T>(getX() * factor, getY() * factor, getZ() * factor);
}

template<class T>
Vector3<T> Vector3<T>::operator/(const Vector3 &other) const
{
    return Vector3<T>(getX() / other.getX(), getY() / other.getY(), getZ() / other.getZ());
}

template<class T>
Vector3<T> Vector3<T>::operator/(float factor) const
{
    float invertedFactor = 1.0f / factor;
    return Vector3<T>(getX() * invertedFactor, getY() * invertedFactor, getZ() * invertedFactor);
}

template<class T>
bool Vector3<T>::operator==(const Vector3 &other) const
{
    T epsilon = std::numeric_limits<T>().epsilon();

    T diffX = getX() - other.getX();
    T diffY = getY() - other.getY();
    T diffZ = getZ() - other.getZ();

    float sqrLen = diffX * diffX + diffY * diffY + diffZ * diffZ;

    return sqrLen < epsilon * epsilon;
}

template<class T>
bool Vector3<T>::operator!=(const Vector3 &other) const
{
    bool equality = *this == other;
    return !equality;
}

template<class T>
T Vector3<T>::length() const
{
    sqrt(sqrLength());
}

template<class T>
T Vector3<T>::sqrLength() const
{
    getX() * getX() + getY() * getY() + getZ() * getZ();
}

template<class T>
void Vector3<T>::normalize() const
{
    float invertedFactor = 1.0f / length();

    setX(getX() * invertedFactor);
    setY(getY() * invertedFactor);
    setZ(getZ() * invertedFactor);
}

template<class T>
T Vector3<T>::dot(const Vector3 &other) const
{
    return getX() * other.getX() + getY() * other.getY() + getZ() * other.getZ();
}

template<class T>
Vector3<T> Vector3<T>::cross(const Vector3 &other) const
{
    return Vector3(
            getY() * other.z - getZ() * other.y,
            getZ() * other.x - getX() * other.z,
            getX() * other.y - getY() * other.x
    );
}






