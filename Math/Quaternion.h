#ifndef TUCANCORE_QUATERNION_H
#define TUCANCORE_QUATERNION_H

#include <array>
#include "Vector3.h"

template<class T>
struct Quaternion final {
private:
    std::array<T, 4> m_components{};

public:
public:
    Quaternion() = default;
    Quaternion(const T& x, const T& y, const T& z, const T& w);
};


#endif
