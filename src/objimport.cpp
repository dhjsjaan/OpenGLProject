#include "objimport.h"
#include "str.h"

namespace LK
{

bool OBJImporter::fromFile(const std::string &filepath, MyMesh *pMesh)
{
    std::ifstream in(filepath, std::ios::in);
    if (!in)
    {
        return false;
    }

    std::vector<glm::vec3> t_vert;

    std::string s_line;
    while (std::getline(in, s_line))
    {
        std::istringstream ss_line(s_line);
        std::string id;
        ss_line >> id;


        if (id == "v")
        {
            //读取顶点
            glm::vec3 v;

            ss_line >> v.x >> v.y >> v.z;

            //在索引前面加入临时顶点
            t_vert.push_back(v);
        }

        // 面
        else if (id == "f")
        {
            // TODO: 四边形
            // TODO: 读取法线和UV的索引
            // TODO: 优化映射
            std::string v1, v2, v3;
            ss_line >> v1 >> v2 >> v3;

            uint32_t vert_idx[3];
            vert_idx[0] = tokenize(v1, '/').at(0);
            vert_idx[1] = tokenize(v2, '/').at(0);
            vert_idx[2] = tokenize(v3, '/').at(0);

            pMesh->addVertexIndex(vert_idx[0] - 1);
            pMesh->addVertexIndex(vert_idx[1] - 1);
            pMesh->addVertexIndex(vert_idx[2] - 1);
        }
    }

    //使用索引来创建顶点
    for (auto v_idx : pMesh->getVertexIndices())
    {
        glm::vec3 vertex = t_vert[v_idx];
    }
    return true;
}


}
