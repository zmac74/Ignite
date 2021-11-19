#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/scene.h>
#include <vector>

#include "model.h"

#include "importer.h"

using namespace importer;

void importer::loadModel(const char* filepath) 
{
	model::Model model = model::Model{};
	
	Assimp::Importer importer;
	const aiScene* scene = importer.ReadFile(filepath, aiProcess_Triangulate);

	processNode(model, scene);
}

void importer::processNode(model::Model model, const aiScene* scene)
{
	aiNode* node = scene->mRootNode;
}

void importer::processMesh(model::Model model, const aiScene* scene, int index)
{
	aiMesh** meshes = scene->mMeshes;
	aiMesh* aimesh = meshes[index];

	model::Mesh mesh = model::Mesh{};

	processPositions(mesh, aimesh);
}

void importer::processPositions(model::Mesh mesh, const aiMesh* aimesh) 
{
	unsigned int vertexAmount = aimesh->mNumVertices;
	std::vector<float> positions;

	for (unsigned int i = 0; i < vertexAmount; i++)
	{
		positions.push_back(aimesh->mVertices[i].x);
		positions.push_back(aimesh->mVertices[i].y);
		positions.push_back(aimesh->mVertices[i].z);
	}

	mesh.vertexArray.position = positions;
}

void importer::processTextureCoords(model::Mesh mesh, const aiMesh* aimesh)
{
	unsigned int vertexAmount = aimesh->mNumVertices;
	std::vector<float> textureCoords;

	const unsigned int uvChannels = aimesh->GetNumUVChannels();
	const aiVector3D* vectors = aimesh->mTextureCoords[0];

	switch (uvChannels)
	{
	case 1:
		for (unsigned int i = 0; i < vertexAmount; i++)//NOTE: 1 texture-coord channel
		{
			textureCoords.push_back(vectors[i].x);
		}

	case 2:
		for (unsigned int i = 0; i < vertexAmount; i++)//NOTE: 2 texture-coord channel
		{
			textureCoords.push_back(vectors[i].x);
			textureCoords.push_back(vectors[i].y);
		}

	case 3:
		for (unsigned int i = 0; i < vertexAmount; i++)//NOTE: 3 texture-coord channel
		{
			textureCoords.push_back(vectors[i].x);
			textureCoords.push_back(vectors[i].y);
			textureCoords.push_back(vectors[i].z);
		}
	}

	mesh.vertexArray.textureCoords = textureCoords;
}

void importer::processNormals(model::Mesh mesh, const aiMesh* aimesh) 
{
	unsigned int vertexAmount = aimesh->mNumVertices;
	std::vector<float> normals;
	
	for (unsigned int i = 0; i < vertexAmount; i++) 
	{
		normals.push_back(aimesh->mNormals[i].x);
		normals.push_back(aimesh->mNormals[i].y);
		normals.push_back(aimesh->mNormals[i].z);
	}

	mesh.vertexArray.normals = normals;
}

void importer::processColors(model::Mesh mesh, const aiMesh* aimesh)
{
	unsigned int vertexAmount = aimesh->mNumVertices;
	std::vector<float> colors;

	const aiColor4D* vectors = aimesh->mColors[0];//temporarly using defualt color system and 4 color channels by default
	for (unsigned int i = 0; i < vertexAmount; i++)
	{
		colors.push_back(vectors[i].r);
		colors.push_back(vectors[i].g);
		colors.push_back(vectors[i].b);
		colors.push_back(vectors[i].a);
	}

	mesh.vertexArray.colors = colors;
}

void importer::processLight(model::Model model, const aiScene* scene) 
{
	unsigned int lightAmount = scene->mNumLights;
	
	for (int i = 0; i < lightAmount; i++) 
	{
		const aiLight* ailight = scene->mLights[i];
		model::Light light = model::Light{};

		light.diffuseColor.r = ailight->mColorDiffuse.r;
		light.diffuseColor.g = ailight->mColorDiffuse.g;
		light.diffuseColor.b = ailight->mColorDiffuse.b;

		light.ambientColor.r = ailight->mColorAmbient.r;
		light.ambientColor.g = ailight->mColorAmbient.g;
		light.ambientColor.b = ailight->mColorAmbient.b;

		light.specularColor.r = ailight->mColorSpecular.r;
		light.specularColor.g = ailight->mColorSpecular.g;
		light.specularColor.b = ailight->mColorSpecular.b;

		light.quadraticAttenuation = ailight->mAttenuationQuadratic;
		light.linearAttenuation = ailight->mAttenuationLinear;
		light.constantAttenuation = ailight->mAttenuationConstant;

		light.direction.x = ailight->mDirection.x;
		light.direction.y = ailight->mDirection.y;
		light.direction.z = ailight->mDirection.z;
	}
}

void importer::processCamera(model::Model model, const aiScene* scene) 
{
	unsigned int cameraAmount = scene->mNumCameras;

	for (int i = 0; i < cameraAmount; i++) 
	{
		const aiCamera* aicamera = scene->mCameras[i];
		model::Camera camera = model::Camera{};

		aiMatrix4x4 mat4;
		aicamera->GetCameraMatrix(mat4); //later must convert to glm and store in current camera

		camera.aspect = aicamera->mAspect;
		camera.farPlane = aicamera->mClipPlaneFar;
		camera.nearPlane = aicamera->mClipPlaneNear;
		camera.horizontalFOV = aicamera->mHorizontalFOV;
		
		camera.lookAt.x = aicamera->mLookAt.x;
		camera.lookAt.y = aicamera->mLookAt.y;
		camera.lookAt.z = aicamera->mLookAt.z;
	}
}