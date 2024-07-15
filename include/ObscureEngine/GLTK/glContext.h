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

      void context_clear(float red, float green, float blue, float alpha);
    };
  }
}