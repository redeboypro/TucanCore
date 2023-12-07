#include "Vector.h"

template<typename T, size_t Size>
bool Vector<T, Size>::operator==(const Vector<T, Size> &other) const
{
    T epsilon = std::numeric_limits<T>().epsilon();

    float sqrLen;
    for (int i = 0; i < Size; i++)
    {
        float diff = m_components[i] - other[i];
        sqrLen += diff * diff;
    }

    return sqrLen < epsilon * epsilon;
}

template<typename T, size_t Size>
bool Vector<T, Size>::operator!=(const Vector<T, Size> &other) const
{
    bool equality = *this == other;
    return !equality;
}
