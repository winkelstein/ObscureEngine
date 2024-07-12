#include "../GLTK/glContext.h"

#include <string_view>
#include <memory>

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

      inline bool isOpen() const { return !glfwWindowShouldClose(this->window); }
    };
  }
}