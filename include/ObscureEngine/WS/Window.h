#pragma once
#include "../GLTK/glContext.h"

#include <string_view>
#include <memory>
#include <tuple>

namespace ObscureEngine
{
  namespace WS
  {
    class Window : public GLTK::glContext
    {
    private:
      GLFWwindow *window;

    public:
      Window(std::string_view name, int width, int height);
      ~Window();

      void swapBuffers();
      void makeContextCurrent();

      void clear(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);

      void pollEvent();
      void close();

      void position(int x, int y);

      inline bool isOpen() const { return !glfwWindowShouldClose(this->window); }
      inline std::tuple<int, int> size() const;
      inline std::tuple<int, int> position() const;

      inline GLFWwindow *__get_native_handler() const { return this->window; }
    };
  }
}

std::tuple<int, int> ObscureEngine::WS::Window::size() const
{
  int width, height;
  glfwGetWindowSize(this->window, &width, &height);
  return std::make_tuple(width, height);
}

std::tuple<int, int> ObscureEngine::WS::Window::position() const
{
  int x, y;
  glfwGetWindowPos(this->window, &x, &y);
  return std::make_tuple(x, y);
}