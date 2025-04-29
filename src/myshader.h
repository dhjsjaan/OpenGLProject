#ifndef MYSHADER_H_
#define MYSHADER_H_

#include "Head.h"

namespace LK
{

class MyShader
{
public:
    MyShader() = default;
    bool load(const std::string& vertexshader_file, const std::string& fragmentshader_file);
    void use();
    void unload();
    unsigned int getSHaderID() {return mShaderID;}

    void SetMat4(const glm::mat4& mat4, const std::string& name);
    void SetInt(int v, const std::string& name);
    void SetFloat(float v, const std::string& name);
    void SetFloat3(float a, float b, float c, const std::string& name);
    void SetVec3(const glm::vec3& vec3, const std::string& name);

private:
    unsigned int mShaderID;
    unsigned int getCompiledShader(unsigned int shader_type, const std::string& shader_source);
};


}

#endif
