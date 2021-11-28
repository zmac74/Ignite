#pragma once

#include <assimp/scene.h>

#include "model.h"

namespace importer 
{
	//FIX: need to pass model and mesh by pointer
	model::Mesh loadModel(const char* filepath);

	void processNode(model::Model model, const aiScene* scene);

	void processMesh(model::Mesh& mesh, const aiScene* scene, int index);

	void processPositions(model::Mesh& mesh, const aiMesh* aimesh);
	void processTextureCoords(model::Mesh& mesh, const aiMesh* aimesh);
	void processNormals(model::Mesh& mesh, const aiMesh* aimesh);
	void processColors(model::Mesh& mesh, const aiMesh* aimesh);

	void processLight(model::Model model, const aiScene* scene);

	void processCamera(model::Model model, const aiScene* scene);
}