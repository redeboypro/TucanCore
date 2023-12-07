//
// Created by redeb on 05.12.2023.
//

#ifndef TUCANCORE_EBO_H
#define TUCANCORE_EBO_H

#include <GL/glew.h>
#include <vector>

struct EBO final {
private:
    GLuint m_id;

public:
    EBO();
    ~EBO();

    template<class T>
    void genBuffer(const std::vector<T>& data);

    template<class T>
    void updateBuffer(const std::vector<T>& data);

    void deleteBuffer();
};


#endif //TUCANCORE_EBO_H
