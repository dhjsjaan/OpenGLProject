#ifndef STR_H_
#define STR_H_

#include "Head.h"

namespace LK
{

std::vector<uint32_t> tokenize(const std::string& line, const char token)//提取字符串转为整数
{
    std::vector<uint32_t> result;

    std::stringstream ss(line);
    std::string item;
    while (std::getline(ss, item, token))//分界
        if (!item.empty())
            result.push_back(std::stoi(item));//转化

    return result;
}

}

#endif
