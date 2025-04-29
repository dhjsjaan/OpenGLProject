#ifndef light_h_
#define light_h_

#include "Head.h"
#include "element.h"
#include "myshader.h"

namespace LK
{

class Light : public Element
{
public:
    Light();
    ~Light() {}

    void update(MyShader* shader) override;

    glm::vec3 mPosition;
    glm::vec3 mColor;
    float mStrength;
};

}

#endif
