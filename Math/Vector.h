#ifndef TUCANCORE_VECTOR_H
#define TUCANCORE_VECTOR_H

#include <limits>
#include <cstddef>

template<typename T, size_t Size>
struct Vector
{
protected:
    T m_components[Size];

public:
    T& operator[](const size_t& inx)
    {
        return m_components[inx];
    }

    bool operator==(const Vector<T, Size>& other) const;
    bool operator!=(const Vector<T, Size>& other) const;
};

#endif
