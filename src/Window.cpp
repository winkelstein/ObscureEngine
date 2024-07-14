#include "../include/ObscureEngine/WS/Window.h"

ObscureEngine::WS::Window::Window(std::string_view name, uint32_t width, uint32_t height)
{
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

  this->context_init(this->window);
  this->makeContextCurrent();
}

ObscureEngine::WS::Window::~Window()
{
  this->context_destroy();
  glfwDestroyWindow(this->window);
  glfwTerminate();
}

void ObscureEngine::WS::Window::swapBuffers()
{
  this->context_swapBuffers();
}

void ObscureEngine::WS::Window::makeContextCurrent()
{
  this->context_makeContextCurrent();
}

void ObscureEngine::WS::Window::clear(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
  this->context_swapBuffers();
  this->context_clear(red, green, blue, alpha);
}

void ObscureEngine::WS::Window::pollEvent() { glfwPollEvents(); }

void ObscureEngine::WS::Window::close()
{
  glfwSetWindowShouldClose(this->window, GLFW_TRUE);
}

void ObscureEngine::WS::Window::position(uint32_t x, uint32_t y)
{
  glfwSetWindowPos(this->window, (int)x, (int)y);
}