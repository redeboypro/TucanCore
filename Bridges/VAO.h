#ifndef TUCANCORE_VAO_H
#define TUCANCORE_VAO_H

#include <unordered_map>
#include "VBO.h"
#include "EBO.h"

struct VAO final {
private:
    GLuint m_id;
    std::unordered_map<int, VBO> m_vertexBufferObjects;
    EBO m_elementBufferObject;

public:
    VAO();
    ~VAO();

    template<class T>
    void genElementBufferObject(const std::vector<T>& data);

    template<class T>
    void updateElementBufferObject(const std::vector<T>& data);

    template<class T>
    void genVertexBufferObject(int attributeLocation, int dimension, const std::vector<T>& data);

    template<class T>
    void updateVertexBufferObject(int attributeLocation, const std::vector<T>& data);

    void deleteBuffers();
};


#endif
