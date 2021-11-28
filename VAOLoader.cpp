#include <GL/glew.h>
#include <vector>

#include "model.h"
#include "data_struct.h"

using namespace data_struct;

std::vector<VAO> vaoList = std::vector<VAO>();

void data_struct::loadMesh(const model::Mesh& mesh)
{
	vaoList.push_back(VAO{});
	
	unsigned int vaoID = createVaoID();

	bindVao(vaoID);
	createAttribute(0, 3, mesh.vertexArray.position);
	createAttribute(1, 2, mesh.vertexArray.textureCoords);
	createAttribute(2, 3, mesh.vertexArray.normals);
	createAttribute(3, 4, mesh.vertexArray.colors);
	unbindVao(vaoID);

	vaoList.back().vertexCount = mesh.vertexArray.position.size() / 3; //temporary way of getting vertex count
	vaoList.back().vaoID = vaoID;
}

unsigned int data_struct::createVaoID() 
{
	unsigned int vaoID;
	glGenVertexArrays(1, &vaoID);

	return vaoID;
}

void data_struct::bindVao(unsigned int vaoID)
{
	glBindVertexArray(vaoID);
}

void data_struct::unbindVao(unsigned int vaoID)
{
	glBindVertexArray(0);
}

void data_struct::createAttribute(int attribute, int vecSize, const std::vector<float>& buffer)
{
	unsigned int vboID;

	glGenBuffers(1, &vboID);
	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glBufferData(GL_ARRAY_BUFFER, buffer.size() * sizeof(float), buffer.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(attribute, vecSize, GL_FLOAT, GL_FALSE, 0, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	vaoList.back().vboList.push_back(vboID);
}