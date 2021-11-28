#include <GL/glew.h>
#include "core.h"

using namespace core;

void core::init() 
{
	glewInit();
	glEnable(GL_DEPTH_TEST);
}