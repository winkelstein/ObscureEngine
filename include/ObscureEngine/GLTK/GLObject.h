#pragma once
#include "Core.h"

namespace ObscureEngine
{
  namespace GLTK
  {
    class GLObject
    {
    protected:
      GLuint instance;

    public:
      virtual void bind() = 0;
      virtual void unbind() = 0;
    };
  }
}