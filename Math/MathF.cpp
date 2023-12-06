#include "MathF.h"

template<class T>
[[maybe_unused]] Matrix4x4<T> static mat4x4_identity()
{
    return Matrix4x4<T>({1, 0, 0, 0},
                        {0, 1, 0, 0},
                        {0, 0, 1, 0},
                        {0, 0, 0, 1});
}

template<class T>
[[maybe_unused]] Matrix4x4<T> static mat4x4_translate(const Vector3<T>& vec)
{
    return Matrix4x4<T>({{1, 0, 0, vec.x},
                         {0, 1, 0, vec.y},
                         {0, 0, 1, vec.z},
                         {0, 0, 0, 1}});
}
