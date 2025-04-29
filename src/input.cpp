#include "input.h"

namespace LK
{

ElementInput Input::GetPressedButton(GLFWwindow *window)
{
    ElementInput result = ElementInput::None;

    if (glfwGetMouseButton(window, 0) == GLFW_PRESS)
        return ElementInput::Left;
    else if (glfwGetMouseButton(window, 1) == GLFW_PRESS)
        return ElementInput::Right;
    else if (glfwGetMouseButton(window, 2) == GLFW_PRESS)
        return ElementInput::Middle;

    return ElementInput::None;
}


}