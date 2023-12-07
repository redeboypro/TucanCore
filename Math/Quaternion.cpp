#include "Quaternion.h"

template<class T>
Quaternion<T>::Quaternion(const T &x, const T &y, const T &z, const T &w) : m_components({x, y, z, w}) {}

