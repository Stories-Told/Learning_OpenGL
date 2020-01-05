#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "shader_s.h"

#include <iostream>

using namespace std;

// forward declartions (HANDY!)
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

// variables for screen width and height
const int WIDTH = 1200, HEIGHT = 800;


int main()
{
	//inititalize GLFW and select the context version
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//creates the window for the application and checks if failed to open
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Learn OpenGL", NULL, NULL);
	if (window == NULL)
	{
		cout << "Failed to create GLFW window!" << endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// starts the GLAD commands for OpenGL
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		cout << "Failed to initialize GLAD" << endl;
		return -1;
	}

	// Reads in the shader files to color the triangles
	Shader redShader("3.3.shader.vs", "redShader.fs");
	Shader yellowShader("3.3.shader.vs", "yellowShader.fs");
	Shader multiColorShader("3.3.shader.vs", "multiColor.fs");


	// Points to make the triangle, based off a x and y grid, ONLY values from -1.0 - 1.0
	float firstTriangle[] = 
	{
		-0.8f, 0.0f, 0.0f,
		 -0.6f, 0.3f, 0.0f, 
		-0.4f, 0.0f, 0.0f
	};

	float secondTriangle[]	=
	{
		-0.2f, 0.0f, 0.0f, 
		0.0f, 0.3f, 0.0f,
		0.2f, 0.0f, 0.0f 
	};

	float thirdTriangle[] = 
	{		// Position		// Color
		0.5f, 0.0f, 0.0f,  1.0f, 0.0f, 0.0f,
		0.7f, 0.3f, 0.0f,  0.0f, 1.0f, 0.0f,
		0.9f, 0.0f, 0.0f,  0.0f, 0.0f, 1.0f 
	};

	// Generate the VAOs, VBOs, and EBOs
	unsigned int VBOs[3], VAOs[3];
	glGenVertexArrays(3, VAOs);
	glGenBuffers(3,VBOs);
	
	// Setting up the VAO and VBO for the first triangle
	glBindVertexArray(VAOs[0]);
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(firstTriangle), firstTriangle, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// No need to unbind due to using different VAO
	// Setting up the VAO and VBO for the second triangle
	glBindVertexArray(VAOs[1]);
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(secondTriangle), secondTriangle, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// Setting up the VAO and VBO for the third triangle
	glBindVertexArray(VAOs[2]);
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[2]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(thirdTriangle), thirdTriangle, GL_STATIC_DRAW);
	// Position attributes
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// Color attributes
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	
	//unbinds the VBO
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//unbinds the VAO
	glBindVertexArray(0);


	//render loop (place all rendering commands in the render loop)
	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		// colors the screen (R,G,B,Alpha)
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Colors the first triangle based off the uniform
		redShader.use();
		// Draw the first triangle (color comes from the above uniform code)
		glBindVertexArray(VAOs[0]);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		// Colors the second triangle yellow
		yellowShader.use();
		// Draw the second triangle
		glBindVertexArray(VAOs[1]);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		// Color third triangle
		multiColorShader.use();
		// Draw the third triangle
		glBindVertexArray(VAOs[2]);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}

// allows for different actions on different key presses
void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}

	if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
	{
		//This allows for the drawing to be done in wireframe mode
	    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}

	if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS)
	{
		//This allows for the drawing to be filled in from wireframe mode
	    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
}

//updates if the window is resized to keep contents the same
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}