#include "myshader.h"

namespace LK
{

bool MyShader::load(const std::string &vertexshader_file, const std::string &fragmentshader_file)
{
    std::ifstream is_vs(vertexshader_file);//读取文件
    const std::string f_vs((std::istreambuf_iterator<char>(is_vs)), std::istreambuf_iterator<char>());//用流迭代器构建

    std::ifstream is_fs(fragmentshader_file);
    const std::string f_fs((std::istreambuf_iterator<char>(is_fs)), std::istreambuf_iterator<char>());

    mShaderID = glCreateProgram();

    unsigned int vs = getCompiledShader(GL_VERTEX_SHADER, f_vs);
    unsigned int fs = getCompiledShader(GL_FRAGMENT_SHADER, f_fs);

    glAttachShader(mShaderID, vs);
    glAttachShader(mShaderID, fs);

    glLinkProgram(mShaderID);
    glValidateProgram(mShaderID);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return true;
}

unsigned int MyShader::getCompiledShader(unsigned int shader_type, const std::string &shader_source)
{
    unsigned int shader_id = glCreateShader(shader_type);

    const char* c_source = shader_source.c_str();
    glShaderSource(shader_id, 1, &c_source, nullptr);
    glCompileShader(shader_id);

    GLint result;
    glGetShaderiv(shader_id, GL_COMPILE_STATUS, &result);

    if (result == GL_FALSE)
    {
        int length;
        glGetShaderiv(shader_id, GL_INFO_LOG_LENGTH, &length);

        GLchar* strInfoLog = new GLchar[length + 1];
        glGetShaderInfoLog(shader_id, length, &length, strInfoLog);

        fprintf(stderr, "Compile error in shader: %s\n", strInfoLog);
        delete[] strInfoLog;
    }

    return shader_id;
}

void MyShader::use()
{
    glUseProgram(mShaderID);
}

void MyShader::unload()
{
    glDeleteProgram(mShaderID);
}

void MyShader::SetVec3(const glm::vec3 &vec3, const std::string &name)
{
    GLint myLoc = glGetUniformLocation(getSHaderID(), name.c_str());
    glProgramUniform3fv(getSHaderID(), myLoc, 1, glm::value_ptr(vec3));
}

void MyShader::SetFloat3(float a, float b, float c, const std::string &name)
{
    GLint myLoc = glGetUniformLocation(getSHaderID(), name.c_str());
    glUniform3f(myLoc, a, b, c);
}

void MyShader::SetFloat(float v, const std::string &name)
{
    GLint myLoc = glGetUniformLocation(getSHaderID(), name.c_str());
    glUniform1f(myLoc, v);
}

void MyShader::SetInt(int v, const std::string &name)
{
    GLint myLoc = glGetUniformLocation(getSHaderID(), name.c_str());
    glUniform1i(myLoc, v);
}

void MyShader::SetMat4(const glm::mat4 &mat4, const std::string &name)
{
    GLint myLoc = glGetUniformLocation(getSHaderID(), name.c_str());
    glUniformMatrix4fv(myLoc, 1, GL_FALSE, glm::value_ptr(mat4));
}



}