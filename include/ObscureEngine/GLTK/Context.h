#include "Core.h"

namespace ObscureEngine
{
  namespace GLTK
  {
    class Context
    {
    public:
      virtual ~Context() {}

      virtual void init(GLFWwindow *window) = 0;
      virtual void destroy() = 0;

      virtual void makeContextCurrent() = 0;
      virtual void swapBuffers() = 0;

      virtual void clear(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) = 0;
    };
  }
}