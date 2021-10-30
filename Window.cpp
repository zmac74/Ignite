#include <Windows.h>
#include <string>

#include "input.h"
#include "gui.h"

using namespace gui;

int windowClassAmount = 0;

Window::Window(int width, int height, const char* title) 
{
	createWindowClass();
	
	ws.width = width;
	ws.height = height;
	ws.title = title;
}

Window::Window(WindowSettings ws)
{
	createWindowClass();
	this->ws = ws;
}

Window::~Window() 
{
	UnregisterClass(wc.lpszClassName, NULL);
}

void Window::create() 
{
	hwnd = CreateWindowEx(
		0,
		wc.lpszClassName,
		toWideTitle(ws.title).c_str(),
		WS_OVERLAPPEDWINDOW,
		ws.xPos,
		ws.yPos,
		ws.width,
		ws.height,
		NULL,
		NULL,
		NULL,
		NULL
	);

	SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)this);

	ShowWindow(hwnd, SW_SHOW);
	update();
}

void Window::update() 
{
	while(PeekMessage(&msg, hwnd, 0, 0, PM_REMOVE) == 1)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	GetWindowRect(hwnd, &windowRect);
	GetClientRect(hwnd, &clientRect);
}

void Window::render() 
{
	
}

bool Window::exists() 
{
	return IsWindow(hwnd);
}

void Window::setVisible(bool isVisible) 
{
	if(isVisible) ShowWindow(hwnd, SW_SHOW);
	else ShowWindow(hwnd, SW_HIDE);
}

void Window::setTitle(const char* title) 
{
	SetWindowText(hwnd, toWideTitle(title).c_str());
}

void Window::destroy() 
{
	DestroyWindow(hwnd);
}

int Window::getXPos() { return windowRect.left; }

int Window::getYPos() { return windowRect.top; }

int Window::getWidth() { return windowRect.right - windowRect.left; }

int Window::getHeight() { return windowRect.bottom - windowRect.top; }

int Window::getClientXPos() { return clientRect.left; }

int Window::getClientYPos() { return clientRect.top; }

int Window::getClientWidth() { return clientRect.right - clientRect.left; }

int Window::getClientHeight() { return clientRect.bottom - clientRect.top; }

void Window::createWindowClass() 
{	
	className = L"Ignite_" + std::to_wstring(windowClassAmount);
	
	wc.lpszClassName = className.c_str();
	wc.lpfnWndProc = input::windowProc;
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.style = CS_DBLCLKS;
	wc.hIcon = NULL;
	wc.hCursor = NULL;

	RegisterClass(&wc);
	windowClassAmount++;
}

std::wstring Window::toWideTitle(std::string title)
{
	std::wstring wstr = std::wstring(title.begin(), title.end());
	return wstr;
}