#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <cerrno>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

std::string getShaderFile(const char* shaderFile);

class Shader {
public:
    GLuint id;
    Shader(const char* vertextShaderFile, const char* fragmentShaderFile);
    void Activate();
    void Delete();
private:
    GLuint vertexShader;
};

#endif // SHADER_H
