// PlantillaGraficos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <stdio.h>
#include <stdlib.h>

#define GLEW_STATIC

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <iostream>

using namespace std;
float angulo = 45.0f;
void actualizar() {
	angulo += 0.01f;
	if (angulo >= 360.0f) {
		angulo = 0.0f;
	}
}
void dibujarTriangulo() {
	glPushMatrix();

	//glTranslatef(-0.7f,-0.5f,0.0f);
	glRotatef(angulo, 0.0f, 1.0f,0.0f);
	//glScalef(0.5f, 1.5f, 1.0f);

	glBegin(GL_TRIANGLES);

	glColor3f(0.0f, 1.0f, 0.33f);
	glVertex3f(0.0f,0.15f,0.0f);
	glVertex3f(-0.15f, -0.15f, 0.0f);
	glVertex3f(0.15f, -0.15f, 0.0f);

	glEnd();
	glPopMatrix();

	glPushMatrix();

	glTranslatef(-0.15f,-0.3f,0.0f);
	glRotatef(angulo, 0.0f, 1.0f, 0.0f);
	//glScalef(0.5f, 1.5f, 1.0f);

	glBegin(GL_TRIANGLES);

	glColor3f(0.0f, 1.0f, 0.33f);
	glVertex3f(0.0f, 0.15f, 0.0f);
	glVertex3f(-0.15f, -0.15f, 0.0f);
	glVertex3f(0.15f, -0.15f, 0.0f);

	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.15f, -0.3f, 0.0f);
	glRotatef(angulo, 0.0f, 1.0f, 0.0f);
	//glScalef(0.5f, 1.5f, 1.0f);

	glBegin(GL_TRIANGLES);

	glColor3f(0.0f, 1.0f, 0.33f);
	glVertex3f(0.0f, 0.15f, 0.0f);
	glVertex3f(-0.15f, -0.15f, 0.0f);
	glVertex3f(0.15f, -0.15f, 0.0f);

	glEnd();
	glPopMatrix();

}

void dibujar() {
	dibujarTriangulo();
}

int main()
{
	//Declarar una ventana
	GLFWwindow* window;

	//Si no se pudo iniciar GLFW
	//Terminamos la ejecución
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}
	//Si se pudo iniciar GLFW
	//Inicializamos la ventana
	window = glfwCreateWindow(600, 600, "Ventana", NULL, NULL);

	//Si no se pudo crear la ventana
	//Terminamos la ejecución
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	//Establecemos la ventana como contexto

	glfwMakeContextCurrent(window);

	//una vez establecido el contexto
	//se activan las funciones "modernas" (gpu)
	glewExperimental = true;

	GLenum errores = glewInit();
	if (errores != GLEW_OK) {
		glewGetErrorString(errores);
	}

	const GLubyte* versionGL = glGetString(GL_VERSION);
	cout << "Version OpenGL: " << versionGL;




	//Ciclo de dibujo (DrawLoop)
	while (!glfwWindowShouldClose(window)) {

		//Establecer región de dibujo
		glViewport(00, 0, 600, 600);
		//Establecemos el color de borrado
		//Valores RGBA
		glClearColor(0.46f, 0.27f, 1.0f, 1);
		//Borrar
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Actualizar valores y dibujar
		dibujar();
		actualizar();
		glfwPollEvents();
		glfwSwapBuffers(window);

	}
	//Después del ciclo de dibujo
	//Eliminamos ventana y procesos de GLFW
	glfwDestroyWindow(window);
	glfwTerminate();

}