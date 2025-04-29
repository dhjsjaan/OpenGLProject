#ifndef VERTEXHOLDER_H_
#define VERTEXHOLDER_H_

#include "Head.h"

namespace LK
{

class VertexHolder
{
public:
    VertexHolder() : mPos(), mNormal() {}

    VertexHolder(const std::vector<std::string> tokens) {}

    VertexHolder(const glm::vec3& pos, const glm::vec3& normal) : mPos(pos), mNormal(normal) {}

    ~VertexHolder() = default;

    glm::vec3 mPos;

    glm::vec3 mNormal;
};

}

#endif
