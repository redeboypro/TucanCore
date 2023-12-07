#include "Matrix.h"

template<typename T, size_t Columns, size_t Rows>
bool Matrix<T, Columns, Rows>::operator==(const Matrix<T, Columns, Rows> &other) const
{
    for (int i = 0; i < Rows; i++)
    {
        if (m_rows[i] != other.m_rows[i])
        {
            return false;
        }
    }

    return true;
}

template<typename T, size_t Columns, size_t Rows>
bool Matrix<T, Columns, Rows>::operator!=(const Matrix<T, Columns, Rows> &other) const
{
    bool equality = *this == other;
    return !equality;
}