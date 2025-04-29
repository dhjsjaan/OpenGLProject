#ifndef FRAMEBUFFER_H_
#define FRAMEBUFFER_H_

#include "Head.h"

namespace LK
{

class FrameBuffer
{
public:
    FrameBuffer() : mFBO { 0 }, mDepthId {0} {}
    virtual void createBuffers(int32_t width, int32_t height) = 0;
    virtual void deleteBuffers() = 0;
    virtual void bind() = 0;
    virtual void unBind() = 0;
    virtual uint32_t getTexture() = 0;

protected:
    uint32_t mFBO = 0;
    uint32_t mTexId = 0;
    uint32_t mDepthId = 0;
    int32_t mWidth = 0;
    int32_t mHeight = 0;
};

}

#endif
