#include "scene.h"
#include "../thirdparty/imgui-docking/imgui.h"

namespace LK
{

void Scene::resize(int32_t width, int32_t height)
{
    mSize.x = width;
    mSize.y = height;
    mFrameBuffer->createBuffers((int32_t)mSize.x, (int32_t) mSize.y);
}

void Scene::render()
{
    mShader->use();

    mLight->update(mShader.get());

    mFrameBuffer->bind();

    if (mMesh)
    {
        mMesh->update(mShader.get());
        mMesh->render();
    }

    mFrameBuffer->unBind();

    ImGui::Begin("Scene");

    ImVec2 viewportPanelSize = ImGui::GetContentRegionAvail();
    mSize = { viewportPanelSize.x, viewportPanelSize.y };

    mCamera->setAspect(mSize.x / mSize.y);
    mCamera->update(mShader.get());

    // 渲染纹理到UI窗口
    uint64_t textureID = mFrameBuffer->getTexture();
    ImGui::Image(reinterpret_cast<void*>(textureID), ImVec2{ mSize.x, mSize.y }, ImVec2{ 0, 1 }, ImVec2{ 1, 0 });

    ImGui::End();
}

void Scene::loadMesh(const std::string &filepath)
{
    if(!mMesh)
        mMesh = std::make_shared<MyMesh>();

    mMesh->load(filepath);
}

void Scene::onMouseMove(double x, double y, ElementInput button)
{
    mCamera->onMouseMove(x, y, button);
}

void Scene::onMouseWheel(double delta)
{
    mCamera->onMouseWheel(delta);
}


}