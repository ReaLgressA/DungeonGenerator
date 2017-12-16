#pragma once
#include "Renderer.h"
#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

using namespace glm;

class GLRenderer :
    public Renderer {
public:
    GLRenderer();
    ~GLRenderer();
    void initialize(int wWidth, int wHeight, char* title) override;
    void renderLoop() override;
    void cleanup() override;
};

