#include "userInputs.h"
#include <GLFW/glfw3.h>
#include <iostream>

double xMousePos;
double yMousePos;

void userInputs::cursorPosCallback(GLFWwindow* window, double xMousePos, double yMousePos)
{
	int windowWidth, windowHeight;
	double normalX, normalY;
	glfwGetWindowSize(window, &windowWidth, &windowHeight);
	normalX = (2.0 * (xMousePos / windowWidth)) - 1.0;
	normalY = 1.0 - (2.0 * (yMousePos / windowHeight));
	std::cout << "Mouse Position: (" << normalX << ", " << normalY << ")" << std::endl;
}

void userInputs::mouseInputCallback(GLFWwindow* window, int button, int action, int mods)
{
	//take mouse inputs, left click to draw, right click to erase
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		std::cout << "Left mouse button pressed!" << std::endl;
	}
	else if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
	{
		std::cout << "Left mouse button released!" << std::endl;
	}

	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
	{
		std::cout << "Right mouse button pressed!" << std::endl;
	}
	else if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE)
	{
		std::cout << "Right mouse button released!" << std::endl;
	}

}

void userInputs::keyInputCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS) // Only trigger on key press
	{
		std::cout << "Key pressed (GLFW code): " << key << std::endl;
	}
	else if (action == GLFW_RELEASE) // Only trigger on key release
	{
		std::cout << "Key released (GLFW code): " << key << std::endl;
	}
}

void userInputs::handleScroll(GLFWwindow* window, double yScrollOffset)
{
	if (yScrollOffset > 0) {
		std::cout << "Scrolled up!" << std::endl;
	}
	else if (yScrollOffset < 0) {
		std::cout << "Scrolled down!" << std::endl;
	}
}

void userInputs::scrollCallback(GLFWwindow* window, double xScrollOffset, double yScrollOffset)
{
	userInputs* instance = static_cast<userInputs*>(glfwGetWindowUserPointer(window));
	if (instance) {
		instance->handleScroll(window, yScrollOffset);
	}
}


void userInputs::WindowCallbacks(GLFWwindow* window)
{
	glfwSetCursorPosCallback(window, cursorPosCallback);
	glfwSetMouseButtonCallback(window, mouseInputCallback);
	glfwSetKeyCallback(window, keyInputCallback);
	glfwSetScrollCallback(window, scrollCallback);
}