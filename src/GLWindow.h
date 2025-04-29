#ifndef GLWindow_h_
#define GLWindow_h_

#include "Head.h"
#include "panel.h"
#include "window.h"
#include "context.h"
#include "uicontext.h"

namespace LK
{

class GLWindow : public LKWindow
{
public:
    GLWindow();
    ~GLWindow();

    bool init(int width, int height, const std::string& title);
    void render();
    void handleInput();
    void* getNativeWindow() override { return mWindow; }
    void setNativeWindow(void* window) { mWindow = (GLFWwindow*)window;}
    void onScroll(double delta) override;
    void onKey(int key, int scancode, int action, int mods) override;
    void onResize(int width, int height) override;
    void onClose() override;
    bool isRunning() { return mIsRunning; }

private:
    GLFWwindow* mWindow;

    // 渲染的上下文
    std::unique_ptr<UIContext> mUICtx;
    std::unique_ptr<LK::LKContext> mRenderCtx;

    //UI组件
    std::unique_ptr<Panel> mPropertyPanel;
    std::unique_ptr<LK::Scene> mSceneView;

    bool mIsRunning;
};


}

#endif
