#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED

#include <GL/glew.h>
#include "Maths/GlmIncludes.h"

class Camera
{
    public:
        Camera();

        void update();

        const glm::vec3& getPosition() const;
        const glm::vec3& getRotation() const;

        const glm::mat4& getProjViewMatrix() const;

    private:
        glm::vec3 m_position;
        glm::vec3 m_rotation;

        glm::mat4 m_projectionMatrix;
        glm::mat4 m_viewMatrix;
        glm::mat4 m_projectionViewMatrix;
};

#endif // CAMERA_H_INCLUDED