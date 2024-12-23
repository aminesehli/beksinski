#define _CRT_SECURE_NO_WARNINGS

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb/stb_image_write.h>

#include <Windows.h>
#include "userInputs.h"

#include <iostream>
#include <vector>

//make class for user inputs
//make function for window resizing
//implement imgui - change color, brush size, make reset button, save button, load button, eraser


int main()
{
	userInputs inputs;
	GLFWwindow* window;

	if (!glfwInit())
		return -1;

	std::cout << "GLFW initialized successfully!" << std::endl;

	unsigned int windowWidth = 720;
	unsigned int windowHeight = 720;


	window = glfwCreateWindow(windowWidth, windowHeight, "Beksinski", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	GLenum glewInitResult = glewInit();
	if (GLEW_OK != glewInitResult) {
		std::cerr << "Error initializing GLEW: " << glewGetErrorString(glewInitResult) << std::endl;
		glfwTerminate();
		return -1;
	}

	std::cout << "GLEW initialized successfully!" << std::endl;
	std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		//////////////////////////

		inputs.cursorPos(window, windowWidth, windowHeight);

		//////////////////////////
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
};