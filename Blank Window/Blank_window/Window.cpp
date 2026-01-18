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

	//This takes a pointer to the window class object
	RegisterClass(&wndClass);

	DWORD style = WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU; //gives title, min and close buttons, and sysmenu displays the buttons

	//Create the dimensions of the window

	int width = 640; //This is just for demonstration, you can also use user defined dimension and redraw the window that way.
	int height = 480;

	RECT rect;
	rect.left = 250;
	rect.top = 250;
	rect.right = rect.left + width;
	rect.bottom = rect.top + height;

	//Need to correct so that the above code is reference to the canvas size, and not the outter boder
	AdjustWindowRect(&rect, style, false); //The bool reference is asking if we are using menus, which we are not for this demo.


	m_hWnd = CreateWindowEx(
		0,
		CLASS_NAME,
		L"Title",
		style,
		rect.left,
		rect.top,
		rect.right - rect.left,
		rect.bottom - rect.top,
		NULL,
		NULL,
		m_hInstance,
		NULL
	);

}

Window::~Window()
{
}

bool Window::ProcessMessages()
{
	return false;
}
