#include "../GLTK/glContext.h"

#include <string_view>
#include <memory>
#include <tuple>

namespace ObscureEngine
{
  namespace WS
  {
    class Window
    {
    private:
      std::unique_ptr<GLTK::Context> context;
      GLFWwindow *window;

    public:
      Window(std::string_view name, uint32_t width, uint32_t height, GLTK::Context *context = new GLTK::glContext());
      ~Window();

      void swapBuffers();
      void makeContextCurrent();

      void clear(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);

      void pollEvent();
      void close();

      void position(uint32_t x, uint32_t y);

      inline bool isOpen() const { return !glfwWindowShouldClose(this->window); }
      inline std::tuple<uint32_t, uint32_t> size() const;
      inline std::tuple<uint32_t, uint32_t> position() const;
    };
  }
}

std::tuple<uint32_t, uint32_t> ObscureEngine::WS::Window::size() const
{
  uint32_t width, height;
  glfwGetWindowSize(this->window, (int *)&width, (int *)&height);
  return std::make_tuple(width, height);
}

std::tuple<uint32_t, uint32_t> ObscureEngine::WS::Window::position() const
{
  uint32_t x, y;
  glfwGetWindowPos(this->window, (int *)&x, (int *)&y);
  return std::make_tuple(x, y);
}