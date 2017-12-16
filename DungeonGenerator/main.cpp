//#define NDEBUG
#include "VulkanRenderer.h"
#include "GLRenderer.h"

int main() {
    Renderer *renderer = nullptr;
    Renderer::RendererType type = Renderer::RendererType::Vulkan; //Renderer::RendererType::OpenGL;
    switch (type) {
        case Renderer::RendererType::OpenGL:
            renderer = new GLRenderer();
            break;
        case Renderer::RendererType::Vulkan:
            renderer = new VulkanRenderer();
            break;
    }
    try {
        renderer->initialize(800, 600, "Demo");
        renderer->run();
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}