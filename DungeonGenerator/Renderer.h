#pragma once
#include <string>
#include <iostream>
#include <stdexcept>
#include <functional>

//Abstract Renderer
class Renderer {
public:
    enum class RendererType { OpenGL, Vulkan };
    virtual ~Renderer() = 0;
    virtual void initialize(int wWidth, int wHeight, char* title) = 0;
    void run() {
        renderLoop();
        cleanup();
    }

protected:
    Renderer(RendererType type) : type(type) {
        std::cout << "Renderer type: " << (type == RendererType::Vulkan ? "Vulkan\n" : "OpenGL\n");
    }
    virtual void renderLoop() = 0;
    virtual void cleanup() = 0;

private:
    RendererType type;

};

inline Renderer::~Renderer() { }