#include "buffermanager.h"
#include "Head.h"

namespace LK
{

void GLVertexIndexBuffer::createBuffers(const std::vector<VertexHolder> &vertices,
                                        const std::vector<unsigned int> &indices)
{
    glGenVertexArrays(1, &mVAO);
    glGenBuffers(1, &mIBO);
    glGenBuffers(1, &mVBO);
    glBindVertexArray(mVAO);

    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(VertexHolder), vertices.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexHolder), (void*)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(VertexHolder), (void*)offsetof(VertexHolder, mNormal));

    glBindVertexArray(0);
}

void GLVertexIndexBuffer::deleteBuffers()
{
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glDeleteBuffers(1, &mIBO);
    glDeleteBuffers(1, &mVBO);
    glDeleteVertexArrays(1, &mVAO);
}

void GLVertexIndexBuffer::bind()
{
    glBindVertexArray(mVAO);
}

void GLVertexIndexBuffer::unBind()
{
    glBindVertexArray(0);
}

void GLVertexIndexBuffer::draw(int index_count)
{
    bind();
    glDrawElements(GL_TRIANGLES, index_count, GL_UNSIGNED_INT, nullptr);
    unBind();
}

void GLFrameBuffer::createBuffers(int32_t width, int32_t height)
{
    mWidth = width;
    mHeight = height;
    if (mFBO)
    {
        deleteBuffers();
    }

    glGenFramebuffers(1, &mFBO);
    glBindFramebuffer(GL_FRAMEBUFFER, mFBO);
    glCreateTextures(GL_TEXTURE_2D, 1, &mTexId);
    glBindTexture(GL_TEXTURE_2D, mTexId);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, mWidth, mHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, mTexId, 0);

    glCreateTextures(GL_TEXTURE_2D, 1, &mDepthId);
    glBindTexture(GL_TEXTURE_2D, mDepthId);
    glTexStorage2D(GL_TEXTURE_2D, 1, GL_DEPTH24_STENCIL8, mWidth, mHeight);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_TEXTURE_2D, mDepthId, 0);

    GLenum buffers[4] = { GL_COLOR_ATTACHMENT0 };
    glDrawBuffers(mTexId, buffers);

    unBind();
}

void GLFrameBuffer::deleteBuffers()
{
    if (mFBO)
    {
        glDeleteFramebuffers(GL_FRAMEBUFFER, &mFBO);
        glDeleteTextures(1, &mTexId);
        glDeleteTextures(1, &mDepthId);
        mTexId = 0;
        mDepthId = 0;
    }
}

void GLFrameBuffer::bind()
{
    glBindFramebuffer(GL_FRAMEBUFFER, mFBO);
    glViewport(0, 0, mWidth, mHeight);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void GLFrameBuffer::unBind()
{
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

uint32_t GLFrameBuffer::getTexture()
{
    return mTexId;
}


}