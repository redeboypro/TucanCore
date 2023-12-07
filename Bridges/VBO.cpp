#include "VBO.h"

VBO::VBO(int attributeLocation, int dimension) : m_attributeLocation(attributeLocation), m_dimension(dimension), m_id(-1) {}

VBO::~VBO()
{
    deleteBuffer();
}

template<class T>
void VBO::genBuffer(const std::vector<T> &data)
{
    glGenBuffers(1, &m_id);
    glBindBuffer(GL_ARRAY_BUFFER, m_id);
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(T), data.data(), GL_DYNAMIC_DRAW);
    glVertexAttribPointer(m_attributeLocation, m_dimension, GL_FLOAT, GL_FALSE, 0, 0);
}

template<class T>
void VBO::updateBuffer(const std::vector<T>& data)
{
    glBindBuffer(GL_ARRAY_BUFFER, m_id);
    glBufferSubData(GL_ARRAY_BUFFER, 0, data.size() * sizeof(T), data.data());
}

void VBO::deleteBuffer()
{
    glDeleteBuffers(1, &m_id);
}
