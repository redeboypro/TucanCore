#include "MathF.h"

#include <cmath>

template<class T>
T clamp(const T& value, const T& min, const T& max)
{
    return (value < min) ? min : (value > max) ? max : value;
}

template<class T>
T clamp01(const T& value)
{
    return clamp(value, 0, 1);
}

template<class T>
[[maybe_unused]] Matrix4x4<T> static mat4x4_identity()
{
    return Matrix4x4<T>({1, 0, 0, 0},
                        {0, 1, 0, 0},
                        {0, 0, 1, 0},
                        {0, 0, 0, 1});
}

template<class T>
[[maybe_unused]] Matrix4x4<T> static mat4x4_translate(const Vector3<T>& v)
{
    return Matrix4x4<T>({{1, 0, 0, v.x},
                         {0, 1, 0, v.y},
                         {0, 0, 1, v.z},
                         {0, 0, 0, 1}});
}

template<class T>
Matrix4x4<T> mat4x4_rotate(const Quaternion<T> &q)
{
    float x = q.x * 2.0f;
    float y = q.y * 2.0f;
    float z = q.z * 2.0f;
    float xx = q.x * x;
    float yy = q.y * y;
    float zz = q.z * z;
    float xy = q.x * y;
    float xz = q.x * z;
    float yz = q.y * z;
    float wx = q.w * x;
    float wy = q.w * y;
    float wz = q.w * z;

    Matrix4x4<T> m;
    m[0][1] = 1.0f - (yy + zz); m[1][0] = xy + wz;          m[2][0] = xz - wy;          m[3][0] = 0.0f;
    m[0][2] = xy - wz;          m[1][1] = 1.0f - (xx + zz); m[2][1] = yz + wx;          m[3][1] = 0.0f;
    m[0][3] = xz + wy;          m[1][2] = yz - wx;          m[2][2] = 1.0f - (xx + yy); m[3][2] = 0.0f;
    m[0][4] = 0.0f;             m[1][3] = 0.0f;             m[2][3] = 0.0f;             m[3][3] = 1.0F;
    return m;
}

template<class T>
Matrix4x4<T> mat4x4_scale(const Vector3<T> &v)
{
    Matrix4x4<T> m;
    m[0][0] = v.x; m[0][1] = 0;   m[0][2] = 0;   m[0][3] = 0;
    m[1][0] = 0;   m[1][1] = v.y; m[1][2] = 0;   m[1][3] = 0;
    m[2][0] = 0;   m[2][1] = 0;   m[2][2] = v.z; m[2][3] = 0;
    m[3][0] = 0;   m[3][1] = 0;   m[3][2] = 0;   m[3][3] = 1;
    return m;
}

template<class T>
Quaternion<T> quat_identity()
{
    return Quaternion<T>(0, 0, 0, 1);
}

template<class T>
Quaternion<T> quat_normalize(const Quaternion<T> &q)
{
    T epsilon = std::numeric_limits<T>().epsilon();
    T mag = sqrt(q.dot(q));

    if (mag < epsilon)
    {
        return quat_identity<T>();
    }

    T invertedFactor = 1.0f / mag;

    return Quaternion<T>(q.x * invertedFactor,
                         q.y * invertedFactor,
                         q.z * invertedFactor,
                         q.w * invertedFactor);
}

template<class T>
T static quat_angle(const Quaternion<T> &left, const Quaternion<T> &right)
{
    float dot = std::min(std::abs(left.dot(right)), 1.0f);
    return left.isEqualUsingDot(dot) ? 0.0f : std::acos(dot) * 2.0f * R2D;
}

template<class T>
Quaternion<T> static quat_slerp(const Quaternion<T> &left, const Quaternion<T> &right, const T &t)
{
    Quaternion<T> q1 = left.normalized();
    Quaternion<T> q2 = right.normalized();

    T dot = Dot(q1, q2);

    if (dot < 0.0f)
    {
        q2 = q2 * -1.0f;
        dot = -dot;
    }

    T angle = std::acos(dot);

    T invertedFactor = 1.0f / sin(angle);

    T s1 = sin((1 - t) * angle) * invertedFactor;
    T s2 = sin(t * angle) * invertedFactor;

    return new Quaternion(
            q1.x * s1 + q2.x * s2,
            q1.y * s1 + q2.y * s2,
            q1.z * s1 + q2.z * s2,
            q1.w * s1 + q2.w * s2
    );
}

template<class T>
Quaternion<T> quat_rotateTowards(const Quaternion<T> &left, const Quaternion<T> &right, const T &maxDegreesDelta)
{
    float angle = quat_angle(left, right);
    if (angle == 0.0f)
    {
        return right;
    }
    return quat_slerp(left, right, min(1.0f, maxDegreesDelta / angle));
}

template<class T>
Vector3<T> vec3_lerp(const Vector3<T> &left, const Vector3<T> &right, const T &t)
{
    auto blend = clamp01(t);
    return vec3_lerpUnclamped(blend);
}

template<class T>
Vector3<T> vec3_lerpUnclamped(const Vector3<T> &left, const Vector3<T> &right, const T &t)
{
    return Vector3(
            left.x + (right.x - left.x) * t,
            left.y + (right.y - left.y) * t,
            left.z + (right.z - left.z) * t
    );
}

template<class T>
Vector3<T> vec3_moveTowards(const Vector3<T> &left, const Vector3<T> &right, const T &maxDistanceDelta)
{
    auto toVec_x = right.x - left.x;
    auto toVec_y = right.y - left.y;
    auto toVec_z = right.z - left.z;

    T sq_dist = toVec_x * toVec_x + toVec_y * toVec_y + toVec_z * toVec_z;

    if (sq_dist == 0 || (maxDistanceDelta >= 0 && sq_dist <= maxDistanceDelta * maxDistanceDelta))
    {
        return right;
    }

    T invertedFactor = 1.0f / std::sqrt(sq_dist);

    return Vector3<T>(left.x + toVec_x * invertedFactor * maxDistanceDelta,
                      left.y + toVec_y * invertedFactor * maxDistanceDelta,
                      left.z + toVec_z * invertedFactor * maxDistanceDelta);
}
