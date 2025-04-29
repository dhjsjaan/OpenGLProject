#ifndef SCENE_H_
#define SCENE_H_

#include "mycamera.h"
#include "mymesh.h"
#include "myshader.h"
#include "buffermanager.h"
#include "light.h"
#include "input.h"

namespace LK
{

class Scene
{
public:
    Scene() : mSize(800, 600)
    {
        mFrameBuffer = std::make_unique<GLFrameBuffer>();
        mFrameBuffer->createBuffers(800, 600);
        mShader = std::make_unique<MyShader>();
        mShader->load("../shaders/vs.shader", "../shaders/fs_pbr.shader");
        mLight = std::make_unique<Light>();
        mCamera = std::make_unique<MyCamera>(glm::vec3(0, 0, 3), 45.0f, 1.3f, 0.1f, 100.0f);

    }

    ~Scene()
    {
        mShader->unload();
    }

    void loadMesh(const std::string& filepath);
    void resize(int32_t width, int32_t height);
    void render();
    void onMouseMove(double x, double y, ElementInput button);
    void onMouseWheel(double delta);

    Light* getLight() { return mLight.get(); }
    void setMesh(std::shared_ptr<MyMesh> mesh) { mMesh = mesh;}
    std::shared_ptr<MyMesh> getMesh() { return mMesh; }
    void reset_view() { mCamera->reset();}

private:
    std::unique_ptr<MyCamera> mCamera {nullptr};
    std::unique_ptr<GLFrameBuffer> mFrameBuffer {nullptr};
    std::unique_ptr<MyShader> mShader {nullptr};
    std::unique_ptr<Light> mLight {nullptr};
    std::shared_ptr<MyMesh> mMesh {nullptr};
    glm::vec2 mSize;
};

}

#endif
