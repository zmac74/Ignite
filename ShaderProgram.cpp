#include <GL/glew.h>

#include "data_types.h"
#include "renderer.h"

using namespace utils;
using namespace renderer;

ShaderProgram::ShaderProgram(Shader vertexShader, Shader fragmentShader)
{
	programID = glCreateProgram();
	glAttachShader(programID, vertexShader.shaderID);
	glAttachShader(programID, fragmentShader.shaderID);
	glLinkProgram(programID);
	glValidateProgram(programID);
}

void ShaderProgram::start() 
{
	glUseProgram(programID);
}

void ShaderProgram::stop() 
{
	glUseProgram(0);
}

void ShaderProgram::uploadFloat(const char* varName, float value)
{
	int location = glGetUniformLocation(programID, varName);
	glUniform1f(location, value);
}

void ShaderProgram::uploadVector3(const char* varName, Vector3 vector)
{
	int location = glGetUniformLocation(programID, varName);
	glUniform3f(location, vector.x, vector.y, vector.z);
}

void ShaderProgram::uploadMatrix4x4(const char* varName, Matrix4x4 matrix)
{
	int location = glGetUniformLocation(programID, varName);
	glUniformMatrix4fv(location, 1, false, matrix.getValuePtr());
}

unsigned int ShaderProgram::getProgramID() { return programID; }