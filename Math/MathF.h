//
// Created by redeb on 05.12.2023.
//

#ifndef TUCANCORE_MATHF_H
#define TUCANCORE_MATHF_H

#include <limits>
#include <cmath>
#include "Vector3.h"
#include "Matrix4x4.h"
#include "Vector4.h"
#include "Quaternion.h"

const float EpsilonF = 0.000001f;

const float D2R = M_PI * 2.0f / 360.0f;

const float R2D = 1.0f / D2R;

template<class T>
[[maybe_unused]] T static clamp(const T& value, const T& min, const T& max);

template<class T>
[[maybe_unused]] T static clamp01(const T& value);

template<class T>
[[maybe_unused]] Matrix4x4<T> static mat4x4_identity();

template<class T>
[[maybe_unused]] Matrix4x4<T> static mat4x4_translate(const Vector3<T>& v);

template<class T>
[[maybe_unused]] Matrix4x4<T> static mat4x4_rotate(const Quaternion<T>& q);

template<class T>
[[maybe_unused]] Matrix4x4<T> static mat4x4_scale(const Vector3<T>& v);

template<class T>
[[maybe_unused]] Vector3<T> static vec3_lerp(const Vector3<T>& left, const Vector3<T>& right, const T& t);

template<class T>
[[maybe_unused]] Vector3<T> static vec3_lerpUnclamped(const Vector3<T>& left, const Vector3<T>& right, const T& t);

template<class T>
[[maybe_unused]] Vector3<T> static vec3_moveTowards(const Vector3<T>& left, const Vector3<T>& right, const T& maxDistanceDelta);

template<class T>
[[maybe_unused]] Quaternion<T> static quat_identity();

template<class T>
[[maybe_unused]] Quaternion<T> quat_normalize(const Quaternion<T> &q);

template<class T>
[[maybe_unused]] T static quat_angle(const Quaternion<T>& left, const Quaternion<T>& right);

template<class T>
[[maybe_unused]] Quaternion<T> static quat_slerp(const Quaternion<T>& left, const Quaternion<T>& right, const T& t);

template<class T>
[[maybe_unused]] Quaternion<T> static quat_rotateTowards(const Quaternion<T>& left, const Quaternion<T>& right, const T& maxDegreesDelta);
#endif
