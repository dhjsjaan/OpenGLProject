#ifndef UICONTEXT_H_
#define UICONTEXT_H_

#include "baserender.h"

namespace LK
{

class UIContext : public RenderContext
{
public:
    bool init(LKWindow* window) override;
    void preRender() override;
    void postRender() override;
    void end() override;
};

}

#endif
