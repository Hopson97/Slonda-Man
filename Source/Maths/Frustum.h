#ifndef FRUSTUM_H_INCLUDED
#define FRUSTUM_H_INCLUDED

#include <array>

#include "GlmIncludes.h"

struct AABB;

struct Plane
{
    float distanceToPoint(const glm::vec3& point) const ;

    float distanceToOrigin;
    glm::vec3 normal;
};

class ViewFrustum
{
    public:
        void update(const glm::mat4& projViewMatrix) noexcept;

        bool isBoxInFrustum     (const AABB& box)           const noexcept;
        bool isPointInFrustum   (const glm::vec3& point)    const noexcept;

    private:
        std::array<Plane, 6> m_planes;
};

struct AABB
{
    AABB(const glm::vec3& dim)
    :   dimensions  (dim)
    {

    }

    void update(const glm::vec3& location)
    {
        position = location;
    }

    glm::vec3 getVN(const glm::vec3& normal)  const
    {
        glm::vec3 res = position;

        if (normal.x < 0)
        {
            res.x += dimensions.x;
        }
        if (normal.y < 0)
        {
            res.y += dimensions.y;
        }
        if (normal.z < 0)
        {
            res.z += dimensions.z;
        }

        return res;
    }

    glm::vec3 getVP(const glm::vec3& normal) const
    {
        glm::vec3 res = position;

        if (normal.x > 0)
        {
            res.x += dimensions.x;
        }
        if (normal.y > 0)
        {
            res.y += dimensions.y;
        }
        if (normal.z > 0)
        {
            res.z += dimensions.z;
        }

        return res;
    }

    glm::vec3 position;
    const glm::vec3 dimensions;
};

#endif // FRUSTUM_H_INCLUDED
