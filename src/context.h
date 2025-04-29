#ifndef CONTEXT_H_
#define CONTEXT_H_

#include "baserender.h"

namespace LK
{

class LKContext : public RenderContext
{
public:
    bool init(LKWindow* window) override;
    void preRender() override;
    void postRender() override;
    void end() override;
};

}

#endif