#ifndef OBJIMPORT_H_
#define OBJIMPORT_H_

#include "baseimport.h"

namespace LK
{

class OBJImporter : public MeshImporter
{
public:
    virtual bool fromFile(const std::string& filepath, MyMesh* pMesh) override;
};

}

#endif
