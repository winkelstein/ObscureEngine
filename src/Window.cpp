#include "../include/ObscureEngine/WS/Window.h"

ObscureEngine::WS::Window::Window(std::string_view name, int width, int height)
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

void ObscureEngine::WS::Window::clear(float red, float green, float blue, float alpha)
{
  this->context_swapBuffers();
  this->context_clear(red, green, blue, alpha);
}

void ObscureEngine::WS::Window::pollEvent() { glfwPollEvents(); }

void ObscureEngine::WS::Window::close()
{
  glfwSetWindowShouldClose(this->window, GLFW_TRUE);
}

void ObscureEngine::WS::Window::position(int x, int y)
{
  glfwSetWindowPos(this->window, x, y);
}