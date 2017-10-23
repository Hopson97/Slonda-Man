#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include "GlmIncludes.h"

#include <SFML/Graphics.hpp>

class Camera;

glm::mat4 createModelMatrix         (const glm::vec3& position, const glm::vec3& rotation);
glm::mat4 createViewMatrix          (const Camera& camera);
glm::mat4 createProjectionMatrix    (const sf::RenderWindow& window);

#endif // MATRIX_H_INCLUDED
