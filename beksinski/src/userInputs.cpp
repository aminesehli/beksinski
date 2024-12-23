#include "userInputs.h"
#include <GLFW/glfw3.h>
#include <iostream>

void userInputs::cursorPos(GLFWwindow* window, int windowWidth, int windowHeight)
{
	//constantly update mousepos
	double posX, posY;

	glfwGetWindowSize(window, &windowWidth, &windowHeight);
	glfwGetCursorPos(window, &posX, &posY);

	//normalise grid coordinates, same as opengl, -1 to 1
	double normalX, normalY;

	if (posX >= 0 && posX <= windowWidth && posY >= 0 && posY <= windowHeight)
	{
		normalX = (2.0 * (posX / windowWidth)) - 1.0;
		normalY = 1.0 - (2.0 * (posY / windowHeight));

		std::cout << "Mouse Position: " << normalX << ", " << normalY << std::endl;
	}
}

void userInputs::mouseInput(GLFWwindow* window, int button, int action)
{
	//take mouse inputs, left click to draw, right click to erase

	if (button == GLFW_MOUSE_BUTTON_LEFT)
	{
		if (action == GLFW_PRESS)
		{
			std::cout << "Left mouse button pressed!" << std::endl;
		}
		else if (action == GLFW_RELEASE)
		{
			std::cout << "Left mouse button released!" << std::endl;
		}
	}

	if (button == GLFW_MOUSE_BUTTON_RIGHT)
	{
		if (action == GLFW_PRESS)
		{
			std::cout << "Right mouse button pressed!" << std::endl;
		}
		else if (action == GLFW_RELEASE)
		{
			std::cout << "Right mouse button released!" << std::endl;
		}
	}

}