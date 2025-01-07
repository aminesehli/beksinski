#pragma once
#include <GLFW/glfw3.h>

//take mouse inputs, hold leftclick to draw, hold right click to erase
//scroll to change brush size
//keyboard inputs for shortcuts, etc saving, loading, opening color picker


//class for user inputs
class userInputs
{
public:
	static void cursorPosCallback(GLFWwindow* window, double xMousePos, double yMousePos); //cursor position callback
	static void mouseInputCallback(GLFWwindow* window, int button, int action, int modsMouse); //mouse input callback
	static void keyInputCallback(GLFWwindow* window, int key, int scancode, int action, int modsKey); //keyboard input callback
	static void handleScroll(GLFWwindow* window, double yScrollOffset); //handle scroll input, done this way due to opengl scroll function not working with static functions
	static void scrollCallback(GLFWwindow* window, double xScrollOffset, double yScrollOffset); //scroll callback
	void WindowCallbacks(GLFWwindow* window);
};