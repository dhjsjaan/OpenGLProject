#ifndef RENDERCONTEXT_H_
#define RENDERCONTEXT_H_

#include "window.h"

namespace LK
{

class RenderContext
{
public:
    RenderContext() : mWindow(nullptr) {}

    virtual bool init(LKWindow* window)
    {
        mWindow = window;
        return true;
    }

    virtual void preRender() = 0;
    virtual void postRender() = 0;
    virtual void end() = 0;

protected:
    LKWindow* mWindow;
};

}

#endif
