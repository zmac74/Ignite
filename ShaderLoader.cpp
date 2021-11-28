#include <GL/glew.h>
#include <iostream>

#include "renderer.h"

using namespace renderer;

Shader renderer::loadShader(const char* src, int type)
{
	unsigned int shaderID = glCreateShader(type);
	glShaderSource(shaderID, 1, &src, nullptr);
	glCompileShader(shaderID);

	//check for error (temporary)
	int  success;
	char infoLog[512];
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);


		if (!success)
		{
			glGetShaderInfoLog(shaderID, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
			std::cout << std::endl << src;
		}

	Shader shader{};
	shader.shaderID = shaderID;
	shader.type = type;

	return shader;
}