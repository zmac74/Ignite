#pragma once

#include <Windows.h>

namespace input
{	
	LRESULT CALLBACK windowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	struct Mouse
	{
	public:
		bool LEFT_BUTTON = false;
		bool RIGHT_BUTTON = false;
		bool MIDDLE_BUTTON = false;

		int xPos = 0;
		int yPos = 0;

		void update(UINT uMsg, LPARAM lParam);
	};

	struct Keyboard
	{
	public:
		void update(UINT uMsg, WPARAM wParam);
	};

	Mouse* getMouse();
	Keyboard* getKeyboard();
}