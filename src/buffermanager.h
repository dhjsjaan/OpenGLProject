#ifndef BUFFERMANAGER_H_
#define BUFFERMANAGER_H_

#include "Head.h"
#include "baserender.h"

namespace LK
{

class GLVertexIndexBuffer : public VertexIndexBuffer
{
public:
    GLVertexIndexBuffer() : VertexIndexBuffer() {}
    void createBuffers(const std::vector<VertexHolder>& vertices, const std::vector<unsigned int>& indices) override;
    void deleteBuffers() override;
    void bind() override;
    void unBind() override;
    void draw(int index_count) override;
};

class GLFrameBuffer : public FrameBuffer
{
public:
    void createBuffers(int32_t width, int32_t height) override;
    void deleteBuffers() override;
    void bind() override;
    void unBind() override;
    uint32_t getTexture() override;
};

}

#endif
