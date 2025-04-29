#ifndef VERTEXINDEXBUFFER_H_
#define VERTEXINDEXBUFFER_H_

#include "vertexholder.h"
#include "Head.h"

namespace LK
{

class VertexIndexBuffer
{
public:
    VertexIndexBuffer() : mVBO{ 0 }, mVAO{ 0 }, mIBO{ 0 } {}
    virtual void createBuffers(const std::vector<VertexHolder>& vertices, const std::vector<unsigned int>& indices) = 0;
    virtual void deleteBuffers() = 0;
    virtual void bind() = 0;
    virtual void unBind() = 0;
    virtual void draw(int index_count) = 0;
protected:
    GLuint mVBO;
    GLuint mVAO;
    GLuint mIBO;
};

}

#endif
