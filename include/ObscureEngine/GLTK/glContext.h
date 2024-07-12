#pragma once
#include "Context.h"

namespace ObscureEngine
{
  namespace GLTK
  {
    class glContext : public Context
    {
    private:
      GLFWwindow *window;

    public:
      void init(GLFWwindow *window) override;
      void destroy() override;

      void makeContextCurrent() override;
      void swapBuffers() override;

      void clear(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) override;
    };
  }
}