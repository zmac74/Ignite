#pragma once

#include <string>

#include "model.h"

#include "data_types.h"

using namespace utils;

namespace renderer 
{
	enum class ShaderType 
	{
		VERTEX, FRAGMENT
	};
	
	struct Shader 
	{
	public:
		int shaderID;
		int type;
	};

	class ShaderProgram
	{
	public:
		ShaderProgram(Shader vertexShader, Shader fragmentShader);

		void start();
		void stop();

		void uploadFloat(const char* varName, float value);
		void uploadVector3(const char* varName, Vector3 vector);
		void uploadMatrix4x4(const char* varName, Matrix4x4 matrix);

		unsigned int getProgramID();

	private:
		unsigned int programID;
	};

	std::string readShader(const char* filepath);

	Shader loadShader(const char* src, int type);

	void renderMesh(model::Mesh mesh);
	void clear();
}