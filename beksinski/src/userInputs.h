#pragma once
#include <GLFW/glfw3.h>

//must normalise grid coordinates, same as opengl, -1 to 1
//constantly update mousepos
//take mouse inputs, hold leftclick to draw, hold right click to erase
//scroll to change brush size
//keyboard inputs for shortcuts, etc saving, loading, opening color picker

class userInputs
{
public:
	void cursorPos(GLFWwindow* window, int windowWidth, int windowHeight);
	void mouseInput(GLFWwindow* window, int button, int action);
	void keyboardInput();
	void scrollInput();
};

