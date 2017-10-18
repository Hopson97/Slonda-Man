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

    private:
        glm::vec3 m_position;
        glm::vec3 m_rotation;
};

#endif // CAMERA_H_INCLUDED
