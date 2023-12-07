#include <cstddef>
#include "Vector.h"

#ifndef TUCANCORE_MATRIX_H
#define TUCANCORE_MATRIX_H

template<typename T, size_t Columns, size_t Rows>
struct Matrix
{

protected:
    Vector<T, Columns> m_rows[Rows];

public:
    Vector<T, Columns>& operator[](const size_t row)
    {
        return m_rows[row];
    }

    bool operator==(const Matrix<T, Columns, Rows>& other) const;
    bool operator!=(const Matrix<T, Columns, Rows>& other) const;
};

#endif
