#include "mymesh.h"
#include "buffermanager.h"

#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/scene.h>

namespace LK
{

void MyMesh::init()
{
    mRenderBufferMgr = std::make_unique<GLVertexIndexBuffer>();
    createBuffers();
}

 MyMesh::~MyMesh()
{
    deleteBuffers();
}

void MyMesh::bind()
{
    mRenderBufferMgr->bind();
}

void MyMesh::createBuffers()
{
    mRenderBufferMgr->createBuffers(mVertices, mVertexIndices);
}

void MyMesh::deleteBuffers()
{
    mRenderBufferMgr->deleteBuffers();
}

bool MyMesh::load(const std::string &filepath)
{
    const uint32_t cMeshImportFlags =
        aiProcess_CalcTangentSpace |
        aiProcess_Triangulate |
        aiProcess_SortByPType |
        aiProcess_GenNormals |
        aiProcess_GenUVCoords |
        aiProcess_OptimizeMeshes |
        aiProcess_ValidateDataStructure;

    Assimp::Importer Importer;

    const aiScene* pScene = Importer.ReadFile(filepath.c_str(), cMeshImportFlags);

    if (pScene && pScene->HasMeshes())
    {
        mVertexIndices.clear();
        mVertices.clear();

        auto* mesh = pScene->mMeshes[0];

        for (uint32_t i = 0; i < mesh->mNumVertices; i++)
        {
            VertexHolder vh;
            vh.mPos = { mesh->mVertices[i].x, mesh->mVertices[i].y ,mesh->mVertices[i].z };
            vh.mNormal = { mesh->mNormals[i].x, mesh->mNormals[i].y ,mesh->mNormals[i].z };

            addVertex(vh);
        }

        for (size_t i = 0; i < mesh->mNumFaces; i++)
        {
            aiFace face = mesh->mFaces[i];

            for (size_t j = 0; j < face.mNumIndices; j++)
                addVertexIndex(face.mIndices[j]);
        }

        init();
        return true;
    }
    return false;
}

void MyMesh::render()
{
    mRenderBufferMgr->draw((int) mVertexIndices.size());
}

void MyMesh::unBind()
{
    mRenderBufferMgr->unBind();
}


}