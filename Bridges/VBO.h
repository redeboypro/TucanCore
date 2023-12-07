#ifndef TUCANCORE_VBO_H
#define TUCANCORE_VBO_H

#include <GL/glew.h>
#include <vector>

struct VBO final {
private:
    int m_attributeLocation;
    int m_dimension;
    GLuint m_id;

public:
    VBO(int attributeLocation, int dimension);
    ~VBO();

    template<class T>
    void genBuffer(const std::vector<T>& data);

    template<class T>
    void updateBuffer(const std::vector<T>& data);

    void deleteBuffer();
};

#endif
