#include "VAO.h"

VAO::VAO() : m_id(0)
{
    glGenVertexArrays(1, &m_id);
}

template<class T>
void VAO::genElementBufferObject(const std::vector<T> &data)
{
    glBindVertexArray(m_id);
    m_elementBufferObject.template genBuffer(data);
    glBindVertexArray(0);
}

template<class T>
void VAO::updateElementBufferObject(const std::vector<T> &data)
{
    glBindVertexArray(m_id);
    m_elementBufferObject.template updateBuffer(data);
    glBindVertexArray(0);
}

template<class T>
void VAO::genVertexBufferObject(int attributeLocation, int dimension, const std::vector<T> &data)
{
    if (m_vertexBufferObjects.find(attributeLocation) != m_vertexBufferObjects.end())
    {
        throw std::runtime_error("VAO: Vertex buffer is already instantiated!");
    }
    glBindVertexArray(m_id);
    VBO vbo(attributeLocation, dimension);
    vbo.template genBuffer(data);
    m_vertexBufferObjects[attributeLocation] = vbo;
    glBindVertexArray(0);
}

template<class T>
void VAO::updateVertexBufferObject(int attributeLocation, const std::vector<T> &data)
{
    if (m_vertexBufferObjects.find(attributeLocation) == m_vertexBufferObjects.end())
    {
        throw std::runtime_error("VAO: Vertex buffer is not instantiated!");
    }
    glBindVertexArray(m_id);
    m_vertexBufferObjects[attributeLocation].template updateBuffer(data);
    glBindVertexArray(0);
}

void VAO::deleteBuffers()
{
    glBindVertexArray(m_id);
    for (auto& vbo : m_vertexBufferObjects)
    {
        vbo.second.deleteBuffer();
    }

    m_elementBufferObject.deleteBuffer();

    glDeleteVertexArrays(1, &m_id);
    glBindVertexArray(0);
}
