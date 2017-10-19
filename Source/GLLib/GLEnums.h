#ifndef GLENUMS_H_INCLUDED
#define GLENUMS_H_INCLUDED

#include <GL/glew.h>

namespace GL
{
    enum class DataType
    {
        UnsignedByte    = GL_UNSIGNED_BYTE,
        UnsignedInt     = GL_UNSIGNED_INT,
    };

    enum class BufferType
    {
        Array   = GL_ARRAY_BUFFER,
        Element = GL_ELEMENT_ARRAY_BUFFER
    };

    enum class Cap //Capability
    {
        Blend       = GL_BLEND,
        CullFace    = GL_CULL_FACE,
        DepthTest   = GL_DEPTH_TEST,
        ScissorTest = GL_SCISSOR_TEST,
        StencilTest = GL_STENCIL_TEST,
    };

    enum class Texture
    {
        Texture2D   = GL_TEXTURE_2D,
        CubeMap     = GL_TEXTURE_CUBE_MAP
    };
}

#endif // GLENUMS_H_INCLUDED
