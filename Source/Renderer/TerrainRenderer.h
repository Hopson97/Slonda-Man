#ifndef TERRAINRENDERER_H_INCLUDED
#define TERRAINRENDERER_H_INCLUDED

#include <vector>

#include "../GLLib/GLFunctions.h"
#include "../Maths/GlmIncludes.h"
#include "../Shaders/Shader.h"
#include "../Texture/Texture2D.h"

class Terrain;
class Camera;

class TerrainRenderer
{
    public:
        TerrainRenderer();

        void add    (const Terrain& terrain);
        void render (const Camera& camera);

    private:
        Shader m_terrainShader;

        GLuint  m_locModelMatrix;
        GLuint  m_locProjViewMatrix;
        GLuint  m_locLightPosition;
        GLuint  m_locLightDirection;

        Texture2D m_floorTexture;

        std::vector<const Terrain*> m_terrains;
};

#endif // TERRAINRENDERER_H_INCLUDED
