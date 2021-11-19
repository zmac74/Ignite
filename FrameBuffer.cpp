#include <Windows.h>

#include "gui.h"

using namespace gui;

FrameBuffer::FrameBuffer(int width, int height) 
{
	this->width = width;
	this->height = height;

	length = width * height;
	aspectRatio = (double)height / (double)width;

	initPFD();
}

void FrameBuffer::initPFD() 
{
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cRedBits = 8;
	pfd.cGreenBits = 8;
	pfd.cBlueBits = 8;
	pfd.cAlphaBits = 8;
	pfd.cDepthBits = 32;
	pfd.cStencilBits = 0;
}

PIXELFORMATDESCRIPTOR FrameBuffer::getPixelFormatDescriptor()
{
	return pfd;
}

int FrameBuffer::getWidth() { return width; }

int FrameBuffer::getHeight() { return height; }

int FrameBuffer::getPixelAmount() { return length; }

double FrameBuffer::getAspectRatio() { return aspectRatio; }