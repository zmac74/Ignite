#include <GL/glew.h>

#include "data_struct.h"

using namespace data_struct;

void data_struct::loadMesh()//will take mesh as param later
{
	vaoList.push_back(VAO{});
	
	unsigned int vaoID = createVaoID();

	bindVao(vaoID);
	createAttribute(0, 3, NULL);
	unbindVao(vaoID);

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

void data_struct::createAttribute(int attribute, int vecSize, float* buffer)
{
	unsigned int vboID;

	glGenBuffers(1, &vboID);
	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(buffer), buffer, GL_STATIC_DRAW);//fix
	glVertexAttribPointer(attribute, vecSize, GL_FLOAT, GL_FALSE, 0, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	vaoList.back().vboList.push_back(vboID);
}