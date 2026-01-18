#include "Window.h"

Window::Window() 
	: m_hInstance(GetModuleHandle(nullptr))
{
	const wchar_t* CLASS_NAME = L"Al's Window Class";

	WNDCLASS wndClass = {};
	
	//These are the parameters establishing the window class
	
	wndClass.lpszClassName = CLASS_NAME;
	wndClass.hInstance = m_hInstance;
	//You can load an icon using a macro called the LoadIcon
	wndClass.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	//Not yet implemented, fix later->leave as nullptr for now
	wndClass.lpfnWndProc = nullptr;
}

Window::~Window()
{
}

bool Window::ProcessMessages()
{
	return false;
}
