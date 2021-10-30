#include <Windows.h>

#include "input.h"

using namespace input;

Mouse mouse = Mouse{};
Keyboard keyboard = Keyboard{};

LRESULT CALLBACK input::windowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	mouse.update(uMsg, lParam);
	keyboard.update(uMsg, wParam);

	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}