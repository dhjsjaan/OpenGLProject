#include "mycamera.h"

namespace LK
{

 MyCamera::MyCamera(const glm::vec3 &position, float fov, float aspect, float near, float far)
{
     mPosition = position;
     mAspect = aspect;
     mNear = near;
     mFar = far;
     mFOV = fov;

     setAspect(mAspect);

     updateViewMatrix();
}

void MyCamera::update(MyShader *shader)
{
     glm::mat4 model{ 1.0f };
     shader->SetMat4(model, "model");
     shader->SetMat4(mViewMatrix, "view");
     shader->SetMat4(getProjection(), "projection");
     shader->SetVec3(mPosition, "camPos");
}

void MyCamera::setAspect(float aspect)
{
     mProjection = glm::perspective(mFOV, aspect, mNear, mFar);
}

void MyCamera::setDistance(float offset)
{
     mDistance += offset;
     updateViewMatrix();
}

const glm::mat4 &MyCamera::getProjection() const
{
     return mProjection;
}

glm::mat4 MyCamera::getViewProjection() const
{
     return mProjection * getViewMatrix();
}

glm::vec3 MyCamera::getUp() const
{
     return glm::rotate(getDirection(), cUp);
}

glm::vec3 MyCamera::getRight() const
{
     return glm::rotate(getDirection(), cRight);
}

glm::vec3 MyCamera::getForward() const
 {
     return glm::rotate(getDirection(), cForward);
 }

glm::quat MyCamera::getDirection() const
 {
     return glm::quat(glm::vec3(-mPitch, -mYaw, 0.0f));
 }

glm::mat4 MyCamera::getViewMatrix() const
 {
     return mViewMatrix;
 }

void MyCamera::onMouseWheel(double delta)
 {
     setDistance(delta * 0.5f);
     updateViewMatrix();
 }

void MyCamera::onMouseMove(double x, double y, ElementInput button)
 {
     glm::vec2 pos2d{ x, y };

     if (button == ElementInput::Right)
     {
         glm::vec2 delta = (pos2d - mCurrentPos2d) * 0.004f;

         float sign = getUp().y < 0 ? -1.0f : 1.0f;
         mYaw += sign * delta.x * cRotationSpeed;
         mPitch += delta.y * cRotationSpeed;

         updateViewMatrix();
     }
     else if (button == ElementInput::Middle)
     {
         glm::vec2 delta = (pos2d - mCurrentPos2d) * 0.003f;

         mFocus += -getRight() * delta.x * mDistance;
         mFocus += getUp() * delta.y * mDistance;

         updateViewMatrix();
     }

     mCurrentPos2d = pos2d;
 }

void MyCamera::reset()
 {
     mFocus = { 0.0f, 0.0f, 0.0f };
     updateViewMatrix();
 }

void MyCamera::updateViewMatrix()
 {
     mPosition =  mFocus - getForward() * mDistance;

     glm::quat orientation = getDirection();
     mViewMatrix = glm::translate(glm::mat4(1.0f), mPosition) * glm::toMat4(orientation);
     mViewMatrix = glm::inverse(mViewMatrix);
 }


}