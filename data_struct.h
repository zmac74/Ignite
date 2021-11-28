#pragma once

#include <vector>

#include "model.h"

namespace data_struct 
{
	struct VAO
	{
	public:
		unsigned int vaoID;
		unsigned int vertexCount;
		std::vector<int> vboList = std::vector<int>();
	};
	
	void loadMesh(const model::Mesh& mesh);

	unsigned int createVaoID();
	void bindVao(unsigned int vaoID);
	void unbindVao(unsigned int vaoID);
	void createAttribute(int attribute, int vecSize, const std::vector<float>& buffer);
}