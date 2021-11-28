#include <GL/glew.h>

#include "data_struct.h"
#include "model.h"

#include "renderer.h"

using namespace data_struct;
using namespace renderer;

extern std::vector<VAO> vaoList;

void renderer::renderMesh(model::Mesh mesh)
{
	glBindVertexArray(vaoList[0].vaoID);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	glEnableVertexAttribArray(3);

	glDrawArrays(GL_TRIANGLES, 0, vaoList[0].vertexCount);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
	glDisableVertexAttribArray(3);
	glBindVertexArray(0);
}

void renderer::clear() 
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
}