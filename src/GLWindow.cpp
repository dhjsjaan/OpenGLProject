#include "GLWindow.h"

namespace LK
{

 GLWindow::GLWindow() : mIsRunning(true), mWindow(nullptr)
{
     mUICtx = std::make_unique<UIContext>();
     mRenderCtx = std::make_unique<LKContext>();
}

 GLWindow::~GLWindow()
{
     mUICtx->end();
     mRenderCtx->end();
}

bool GLWindow::init(int width, int height, const std::string &title)
{
     Width = width;
     Height = height;
     Title = title;

     mRenderCtx->init(this);

     mUICtx->init(this);

     mSceneView = std::make_unique<Scene>();

     mPropertyPanel = std::make_unique<Panel>();

     mPropertyPanel->setMeshLoadCallback(
       [this](std::string filepath) { mSceneView->loadMesh(filepath); });

     return mIsRunning;
}

void GLWindow::handleInput()
{
     if (glfwGetKey(mWindow, GLFW_KEY_W) == GLFW_PRESS)
     {
         mSceneView->onMouseWheel(-0.4f);
     }

     if (glfwGetKey(mWindow, GLFW_KEY_S) == GLFW_PRESS)
     {
         mSceneView->onMouseWheel(0.4f);
     }

     if (glfwGetKey(mWindow, GLFW_KEY_F) == GLFW_PRESS)
     {
         mSceneView->reset_view();
     }

     double x, y;
     glfwGetCursorPos(mWindow, &x, &y);
     mSceneView->onMouseMove(x, y, Input::GetPressedButton(mWindow));
}

void GLWindow::onClose()
{
     mIsRunning = false;
}

void GLWindow::onKey(int key, int scancode, int action, int mods)
{
     if (action == GLFW_PRESS)
     {
     }
}

void GLWindow::onResize(int width, int height)
{
     Width = width;
     Height = height;
     mSceneView->resize(Width, Height);
     render();
}

void GLWindow::onScroll(double delta)
{
     mSceneView->onMouseWheel(delta);
}

void GLWindow::render()
{
     //清除
     mRenderCtx->preRender();

     //初始化UI组件
     mUICtx->preRender();

     //渲染物体到场景
     mSceneView->render();
     mPropertyPanel->render(mSceneView.get());

     // 渲染UI
     mUICtx->postRender();

     //检测输入，交换缓冲
     mRenderCtx->postRender();

     handleInput();
}




}