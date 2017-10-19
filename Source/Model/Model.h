#ifndef MODEL_H_INCLUDED
#define MODEL_H_INCLUDED

#include <vector>

#include "../Util/NonCopyable.h"
#include <GL/glew.h>

class Model : public NonCopyable
{
    public:
        Model() = default;
        Model(const std::vector<GLfloat>& vertexPositions,
              const std::vector<GLfloat>& textureCoordinates,
              const std::vector<GLuint>&  indices);

        void create(const std::vector<GLfloat>& vertexPositions,
                    const std::vector<GLfloat>& textureCoordinates,
                    const std::vector<GLuint>&  indices);

        void addVBO(int dim, const std::vector<GLfloat>& data);

        void bindVAO() const ;
        GLuint getIndicesCount() const;

        ~Model();

    private:
        void createEBO(const std::vector<GLuint>&  indices);

        std::vector<GLuint> m_VBOs;
        GLuint m_VAO = 0;
        GLuint m_indicesCount = 0;


};

#endif // MODEL_H_INCLUDED