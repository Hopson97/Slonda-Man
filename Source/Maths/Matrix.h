#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include "GlmIncludes.h"

class Camera;

glm::mat4 createModelMatrix     (const glm::vec3& position, const glm::vec3& rotation);
glm::mat4 createViewMatrix      (const Camera& camera);
glm::mat4 makeProjectionMatrix  ();

#endif // MATRIX_H_INCLUDED
