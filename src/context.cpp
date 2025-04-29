#include "context.h"

namespace LK
{

static void on_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    auto pWindow = static_cast<LKWindow*>(glfwGetWindowUserPointer(window));
    pWindow->onKey(key, scancode, action, mods);
}

static void on_scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    auto pWindow = static_cast<LKWindow*>(glfwGetWindowUserPointer(window));
    pWindow->onScroll(yoffset);
}

static void on_window_size_callback(GLFWwindow* window, int width, int height)
{
    auto pWindow = static_cast<LKWindow*>(glfwGetWindowUserPointer(window));
    pWindow->onResize(width, height);
}

static void on_window_close_callback(GLFWwindow* window)
{
    LKWindow* pWindow = static_cast<LKWindow*>(glfwGetWindowUserPointer(window));
    pWindow->onClose();
}

bool LKContext::init(LKWindow *window)
{
    RenderContext::init(window);
    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return false;
    }

    auto glWindow = glfwCreateWindow(window->Width, window->Height, window->Title.c_str(), nullptr, nullptr);
    window->setNativeWindow(glWindow);

    if (!glWindow)
    {
        std::cerr << "Failed to create GLFW window" << std::endl;
        return false;
    }

    glfwSetWindowUserPointer(glWindow, window);
    glfwSetKeyCallback(glWindow, on_key_callback);
    glfwSetScrollCallback(glWindow, on_scroll_callback);
    glfwSetWindowSizeCallback(glWindow, on_window_size_callback);
    glfwSetWindowCloseCallback(glWindow, on_window_close_callback);
    glfwMakeContextCurrent(glWindow);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return false;
    }

    glEnable(GL_DEPTH_TEST);

    return true;
}

void LKContext::preRender()
{
    glViewport(0, 0, mWindow->Width, mWindow->Height);
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void LKContext::postRender()
{
    glfwPollEvents();
    glfwSwapBuffers((GLFWwindow*) mWindow->getNativeWindow());
}

void LKContext::end()
{
    glfwDestroyWindow((GLFWwindow*)mWindow->getNativeWindow());
    glfwTerminate();
}


}