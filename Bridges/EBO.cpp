#include "EBO.h"

EBO::EBO() : m_id(-1) {}

EBO::~EBO()
{
    deleteBuffer();
}

template<class T>
void EBO::genBuffer(const std::vector<T> &data)
{
    glGenBuffers(1, &m_id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, data.size() * sizeof(T), data.data(), GL_DYNAMIC_DRAW);
}

template<class T>
void EBO::updateBuffer(const std::vector<T>& data)
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
    glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, data.size() * sizeof(T), data.data());
}

void EBO::deleteBuffer()
{
    glDeleteBuffers(1, &m_id);
}
