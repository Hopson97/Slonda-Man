#include "Matrix.h"

#include "../Camera.h"

glm::mat4 createModelMatrix(const glm::vec3& position, const glm::vec3& rotation)
{
    glm::mat4 matrix;

    matrix = glm::translate(matrix, position);
    matrix = glm::rotate(matrix, glm::radians(rotation.x), {1, 0, 0});
    matrix = glm::rotate(matrix, glm::radians(rotation.y), {0, 1, 0});
    matrix = glm::rotate(matrix, glm::radians(rotation.z), {0, 0, 1});



    return matrix;
}

glm::mat4 createViewMatrix(const Camera& camera)
{
    glm::mat4 matrix;

    matrix = glm::rotate(matrix, glm::radians(camera.getRotation().x), {1, 0, 0});
    matrix = glm::rotate(matrix, glm::radians(camera.getRotation().y), {0, 1, 0});
    matrix = glm::rotate(matrix, glm::radians(camera.getRotation().z), {0, 0, 1});

    matrix = glm::translate(matrix, -camera.getPosition());

    return matrix;
}

glm::mat4 createProjectionMatrix(const sf::RenderWindow& window)
{
    return glm::perspective(glm::radians(90.0f),
                            GLfloat(window.getSize().x / window.getSize().y),
                            0.1f,
                            1500.0f);
}
