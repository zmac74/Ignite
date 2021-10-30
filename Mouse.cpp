#include <Windows.h>
#include <WindowsX.h>

#include "input.h"

using namespace input;

void Mouse::update(UINT uMsg, LPARAM lParam) 
{
	switch (uMsg)
	{
		xPos = GET_X_LPARAM(lParam);
		yPos = GET_Y_LPARAM(lParam);
	
		case WM_LBUTTONDOWN: LEFT_BUTTON = true;
		case WM_LBUTTONUP: LEFT_BUTTON = false;

		case WM_RBUTTONDOWN: RIGHT_BUTTON = true;
		case WM_RBUTTONUP: RIGHT_BUTTON = false;

		case WM_MBUTTONDOWN: MIDDLE_BUTTON = true;
		case WM_MBUTTONUP: MIDDLE_BUTTON = false;
	}
}