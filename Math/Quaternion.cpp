#include "Quaternion.h"

template<class T>
Quaternion<T>::Quaternion(const T &x, const T &y, const T &z, const T &w) : m_components({x, y, z, w}) {}

template<class T>
T Quaternion<T>::getX() const
{
    return m_components[0];
}

template<class T>
T Quaternion<T>::getY() const
{
    return m_components[1];
}

template<class T>
T Quaternion<T>::getZ() const
{
    return m_components[2];
}

template<class T>
T Quaternion<T>::getW() const
{
    return m_components[3];
}

template<class T>
void Quaternion<T>::setX(const T &x)
{

}

template<class T>
void Quaternion<T>::setY(const T &y)
{

}

template<class T>
void Quaternion<T>::setZ(const T &z)
{

}

template<class T>
void Quaternion<T>::setW(const T &z)
{

}

