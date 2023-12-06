//
// Created by redeb on 05.12.2023.
//

#ifndef TUCANCORE_MATHF_H
#define TUCANCORE_MATHF_H

#include <limits>
#include "Vector3.h"
#include "Matrix4x4.h"

const float EpsilonF = 0.000001f;

template<class T>
[[maybe_unused]] Matrix4x4<T> static mat4x4_identity();

template<class T>
[[maybe_unused]] Matrix4x4<T> static mat4x4_translate(const Vector3<T>& vec);

#endif
