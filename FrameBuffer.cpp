#include "gui.h"

using namespace gui;

FrameBuffer::FrameBuffer(int width, int height) 
{
	this->width = width;
	this->height = height;

	length = width * height;
	aspectRatio = (double)height / (double)width;
}