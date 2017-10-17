#ifndef MODEL_H_INCLUDED
#define MODEL_H_INCLUDED

#include <vector>

#include "Util/NonCopyable.h"
#include <GL/glew.h>

class Model : public NonCopyable
{
    public:
        Model() = default;
        Model(const std::vector<GLfloat>& vertexPositions);

        void create(const std::vector<GLfloat>& vertexPositions);

        void addVBO(int dim, const std::vector<GLfloat>& data);

        void bindVAO();

        ~Model();

    private:
        std::vector<GLuint> m_VBOs;
        GLuint m_VAO = 0;


};

#endif // MODEL_H_INCLUDED
