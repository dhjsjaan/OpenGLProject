#ifndef MYMESH_H_
#define MYMESH_H_

#include "Head.h"
#include "element.h"
#include "vertexholder.h"
#include "baserender.h"

namespace LK
{

class MyMesh : public Element
{
public:
    MyMesh() = default;

    virtual ~MyMesh();

    bool load(const std::string& filepath);

    void addVertex(const VertexHolder& vertex) { mVertices.push_back(vertex);  }

    void addVertexIndex(unsigned int vertex_idx) { mVertexIndices.push_back(vertex_idx); }

    std::vector<unsigned int> getVertexIndices() { return mVertexIndices; }

    void update(MyShader* shader) override
    {
        //pbr
        shader->SetVec3(mColor, "albedo");

        shader->SetFloat(mRoughness, "roughness");
        shader->SetFloat(mMetallic, "metallic");
        shader->SetFloat(1.0f, "ao");

    }

    glm::vec3 mColor = { 1.0f, 0.0f, 0.0f };
    float mRoughness = 0.2f;
    float mMetallic = 0.1f;

    void init();
    void createBuffers();
    void deleteBuffers();
    void render();
    void bind();
    void unBind();

private:
    // 基类装子类
    std::unique_ptr<VertexIndexBuffer> mRenderBufferMgr;

    // Vertices 和 indices
    std::vector<VertexHolder> mVertices;
    std::vector<unsigned int> mVertexIndices;
};

}

#endif
