#ifndef input_h_
#define input_h_

#include "Head.h"

namespace LK
{

enum class ElementInput//按钮映射
{
    Left = 0,
    Right = 1,
    Middle = 2,
    None = 9
};

class Input
{
public:
    static ElementInput GetPressedButton(GLFWwindow* window);
};

}

#endif
