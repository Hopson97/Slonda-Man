#ifndef SKYBOXRENDERER_H_INCLUDED
#define SKYBOXRENDERER_H_INCLUDED

#include "../Shaders/Shader.h"
#include "../Texture/TextureCube.h"
#include "../Model/Model.h"

class Camera;

class SkyboxRenderer
{
    public:
        SkyboxRenderer();

        void render(const Camera& camera);

    private:
        void loadUnifroms(const Camera& camera);

        GLuint m_locationView = 0;
        GLuint m_locationProj = 0;

        Model       m_skyBoxCube;
        TextureCube m_skyTexture;
        Shader      m_skyShader;
};

#endif // SKYBOXRENDERER_H_INCLUDED
