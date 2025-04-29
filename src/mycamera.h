#ifndef MYCAMERA_H_
#define MYCAMERA_H_

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/quaternion.hpp>

#include "input.h"
#include "element.h"
#include "myshader.h"

namespace LK
{

class MyCamera : public Element
{
public:
    MyCamera(const glm::vec3& position, float fov, float aspect, float near, float far);

    void update(MyShader* shader) override;
    void setAspect(float aspect);
    void setDistance(float offset);
    const glm::mat4& getProjection() const;
    glm::mat4 getViewProjection() const;
    glm::vec3 getUp() const;
    glm::vec3 getRight() const;
    glm::vec3 getForward() const;
    glm::quat getDirection() const;
    glm::mat4 getViewMatrix() const;
    void onMouseWheel(double delta);
    void reset();
    void onMouseMove(double x, double y, ElementInput button);
    void updateViewMatrix();

private:
    glm::mat4 mViewMatrix;
    glm::mat4 mProjection = glm::mat4{ 1.0f };
    glm::vec3 mPosition = { 0.0f, 0.0f, 0.0f };

    glm::vec3 mFocus = { 0.0f, 0.0f, 0.0f };

    float mDistance = 5.0f;
    float mAspect;
    float mFOV;
    float mNear;
    float mFar;

    float mPitch = 0.0f;
    float mYaw = 0.0f;

    glm::vec2 mCurrentPos2d = { 0.0f, 0.0f };

    const glm::vec3 cRight = { 1.0f, 0.0f, 0.0f };
    const glm::vec3 cUp = { 0.0f, 1.0f, 0.0f };
    const glm::vec3 cForward = { 0.0f, 0.0f, -1.0f };

    const float cRotationSpeed = 2.0f;
};

}

#endif
