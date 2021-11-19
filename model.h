#pragma once

#include <vector>

#include "data_types.h"

using namespace utils;

namespace model
{
	struct Transform
	{
	public:
		Matrix4x4 transformation{};

		static Matrix4x4 convertToMatrix();
	};

	enum class ObjectType
	{
		MESH = 0,
		LIGHT = 1,
		CAMERA = 2
	};
	
	struct Node
	{
	public:
		Node(Node* parent, const char* name, Transform transform, ObjectType type);

		ObjectType getType();

	private:
		Node* parent;
		std::vector<Node*> children = std::vector<Node*>();
		const char* name;
		ObjectType type;

		Transform transform;
	};
	
	struct VertexArray
	{
	public:
		std::vector<float> position;
		std::vector<float> textureCoords;
		std::vector<float> normals;
		std::vector<float> colors;
	};

	struct Mesh 
	{
	public:
		VertexArray vertexArray = VertexArray{};
		std::vector<int> indeces;
	};

	struct Light 
	{
	public:
		Color3 diffuseColor{};
		Color3 ambientColor{};
		Color3 specularColor{};
		
		Vector3 direction{};

		float quadraticAttenuation = 0;
		float linearAttenuation = 0;
		float constantAttenuation = 0;

		float calculateLight(float dist);
	};

	struct Camera
	{
	public:
		Transform cameraMatrix{};

		Vector3 lookAt{};
		
		float aspect = 0;
		float nearPlane = 0;
		float farPlane = 0;
		float horizontalFOV = 0;
	};

	struct Model
	{
	public:
		Node* rootNode;
	};
}