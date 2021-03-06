#pragma once

#include <Windows.h>
#include <string>

namespace gui 
{
	class FrameBuffer 
	{
	public:
		FrameBuffer(int width, int height);
		
		PIXELFORMATDESCRIPTOR getPixelFormatDescriptor();
		int getWidth();
		int getHeight();
		int getPixelAmount();
		double getAspectRatio();

	private:
		int width, height;
		int length;
		double aspectRatio;

		PIXELFORMATDESCRIPTOR pfd = PIXELFORMATDESCRIPTOR{};

		void initPFD();
	};
	
	struct WindowSettings 
	{
	public:
		int xPos = CW_USEDEFAULT;
		int yPos = CW_USEDEFAULT;
		int width = CW_USEDEFAULT;
		int height = CW_USEDEFAULT;

		const char* title = "Window";
	};
	
	class Window
	{
	public:
		Window(int width, int height, const char* title);
		Window(WindowSettings ws);
		~Window();

		void create();
		void update();
		void render();
		void destroy();
		void setVisible(bool isVisible);
		void setTitle(const char* title);
		bool exists();

		FrameBuffer getFrameBuffer();
		int getXPos();
		int getYPos();
		int getWidth();
		int getHeight();
		int getClientXPos();
		int getClientYPos();
		int getClientWidth();
		int getClientHeight();

	private:
		WNDCLASS wc = WNDCLASS{};
		std::wstring className;
		
		WindowSettings ws = WindowSettings{};
		HWND hwnd = NULL;
		MSG msg = MSG{};

		RECT windowRect = RECT{};
		RECT clientRect = RECT{};

		FrameBuffer frameBuffer = FrameBuffer(0, 0);//fix later
		HDC dc = NULL;
		HGLRC rc = NULL;

		void createWindowClass();
		static std::wstring toWideTitle(std::string title);
	};
}