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
#include "renderer.h"
#include "vertexBuffer.h"
#include "indexBuffer.h"
#include "brushes.h"

#include <iostream>
#include <math.h>
#include <vector>

//make class for user inputs
//make function for window resizing
//implement imgui - change color, brush size, make reset button, save button, load button, eraser

int main()
{
	userInputs inputs;
	brushes brush;
	GLFWwindow* window;

	if (!glfwInit())
		return -1;

	std::cout << "GLFW initialized successfully!" << std::endl;

	unsigned int windowWidth = 1300;
	unsigned int windowHeight = 1300;

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

	//callbacks
	inputs.WindowCallbacks(window);

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		//////////////////////////
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);

		int width, height;
		glfwGetFramebufferSize(window, &width, &height);

		float radius = 0.1f;
		int segments = 100;
		float x = (2.0 * (xpos / width)) - 1.0;
		float y = 1.0 - (2.0 * (ypos / height));

		brush.drawCircle(x, y, radius, segments);

		//////////////////////////
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
};