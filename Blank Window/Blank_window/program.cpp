#include <iostream>
#include "Window.h"

int main() {

	std::cout << "Creating window\n";

	Window* pWindow = new Window();

	bool running = true;

	while (running) {

		if (!pWindow->ProcessMessages()) {
			std::cout << "Closing Window\n";
			running = false;
		}

		//Render the window

		Sleep(10);
	}

	delete pWindow; //remove the window from memory
	return 0;
}