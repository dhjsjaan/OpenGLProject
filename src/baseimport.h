#ifndef BASEIMPORT_H_
#define BASEIMPORT_H_

#include "Head.h"
#include "mymesh.h"

namespace LK
{

//读取器虚类
struct MeshImporter
{
    virtual bool fromFile(const std::string& filepath, MyMesh* pMesh) = 0;
};

}

#endif
