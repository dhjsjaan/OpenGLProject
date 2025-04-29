#ifndef element_h_
#define element_h_

#include "myshader.h"

namespace LK
{

class Element
{
public:
    virtual void update(MyShader* shader) = 0;
};

}

#endif
