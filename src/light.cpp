#include "light.h"

namespace LK
{

 Light::Light()
{
     mColor = glm::vec3(1.0f, 1.0f, 1.0f);
     mPosition = { 1.5f, 3.5f, 3.0f };
     mStrength = 100.0f;
}

void Light::update(MyShader *shader)
{
     shader->SetVec3(mPosition, "lightPosition");
     shader->SetVec3(mColor * mStrength, "lightColor");
}




}