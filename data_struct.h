#pragma once

#include <vector>

namespace data_struct 
{
	struct VAO
	{
	public:
		unsigned int vaoID;
		unsigned int vertexCount;
		std::vector<int> vboList = std::vector<int>();
	};

	std::vector<VAO> vaoList = std::vector<VAO>();
	
	void loadMesh();

	unsigned int createVaoID();
	void bindVao(unsigned int vaoID);
	void unbindVao(unsigned int vaoID);
	void createAttribute(int attribute, int vecSize, float* buffer);
}