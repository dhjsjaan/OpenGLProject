#ifndef WINDOW_H_
#define WINDOW_H_

#include "string"

namespace LK
{

class LKWindow
{
public:
    virtual void* getNativeWindow() = 0;

    virtual void setNativeWindow(void* window) = 0;

    virtual void onScroll(double delta) = 0;

    virtual void onKey(int key, int scancode, int action, int mods) = 0;

    virtual void onResize(int width, int height) = 0;

    virtual void onClose() = 0;

    int Width;
    int Height;
    std::string Title;
};

}

#endif