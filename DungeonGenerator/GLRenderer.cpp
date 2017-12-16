#include "GLRenderer.h"

GLRenderer::GLRenderer() : Renderer(RendererType::OpenGL) { }

GLRenderer::~GLRenderer() {

}

void GLRenderer::initialize(int wWidth, int wHeight, char * title) {
    if (!glfwInit()) {
        fprintf(stderr, "Ошибка при инициализации GLFWn");
        //return -1;
        return;
    }
    glfwWindowHint(GLFW_SAMPLES, 4); // 4x FSAA
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //OpenGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // no old OpenGL

    GLFWwindow* window;
    window = glfwCreateWindow(1024, 768, "OpenGL 3.3 4xFSAA window", NULL, NULL);
    if (window == NULL) {
        fprintf(stderr, "Impossible to create GLFW window. OpenGL version is less than 3.3\n");
        glfwTerminate();
        //return -1;
        return;
    }
    glfwMakeContextCurrent(window);

    // Инициализируем GLEW
    glewExperimental = true; // Флаг необходим в Core-режиме OpenGL
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Can't initialize GLEW\n");
        //return -1;
        return;
    }

    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    do {

        glfwSwapBuffers(window);
        glfwPollEvents();

    } while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);
}

void GLRenderer::renderLoop() { }

void GLRenderer::cleanup() { }
