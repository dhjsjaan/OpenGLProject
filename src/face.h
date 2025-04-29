#ifndef face_h_
#define face_h_

#include "Head.h"

namespace LK
{

class Face
{
public:
    void addVertexIndex(GLuint index);

private:
    std::vector<GLuint> mVertexIndices;
};

}

#endif
