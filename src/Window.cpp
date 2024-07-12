#include "../include/ObscureEngine/WS/Window.h"

ObscureEngine::WS::Window::Window(std::string_view name, uint32_t width, uint32_t height, GLTK::Context *context)
{
  this->context = std::unique_ptr<GLTK::Context>(context);

  if (!glfwInit())
  {
    throw std::runtime_error("Failed to initialize GLFW");
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

  this->window = glfwCreateWindow(width, height, name.data(), nullptr, nullptr);
  if (this->window == nullptr)
  {
    throw std::runtime_error("Failed to create a window");
  }

  this->context->init(this->window);
  this->context->makeContextCurrent();
}

ObscureEngine::WS::Window::~Window()
{
  this->context->destroy();
  glfwDestroyWindow(this->window);
  glfwTerminate();
}

void ObscureEngine::WS::Window::swapBuffers()
{
  this->context->swapBuffers();
}

void ObscureEngine::WS::Window::makeContextCurrent()
{
  this->context->makeContextCurrent();
}

void ObscureEngine::WS::Window::clear(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
  this->context->swapBuffers();
  this->context->clear(red, green, blue, alpha);
}

void ObscureEngine::WS::Window::pollEvent() { glfwPollEvents(); }

void ObscureEngine::WS::Window::close()
{
  glfwSetWindowShouldClose(this->window, GLFW_TRUE);
}