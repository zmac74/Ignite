#pragma once

#include <glm/glm.hpp>

namespace utils
{
	struct Matrix4x4 
	{
	public:
		glm::mat4 matrix;

		float* getValuePtr();
	};

	struct Matrix3x3
	{
	public:
		glm::mat3 matrix;
	};

	struct Vector4
	{
	public:
		float x, y, z, w;
	};

	struct Vector3
	{
	public:
		float x, y, z;

		float getLength();
	};

	struct Vector2
	{
	public:
		float x, y;
	};

	struct Color4
	{
	public:
		float r, g, b, a;
	};

	struct Color3
	{
	public:
		float r, g, b;
	};

	struct Color32
	{
	public:
		unsigned char r, g, b, a;
	};

	struct Color24
	{
	public:
		unsigned char r, g, b;
	};
}