#pragma once
#include "Core.h"

namespace ObscureEngine
{
  namespace GLTK
  {
    class glContext
    {
    private:
      GLFWwindow *window;

    protected:
      void context_init(GLFWwindow *window);
      void context_destroy();

      void context_makeContextCurrent();
      void context_swapBuffers();

      void context_clear(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
    };
  }
}