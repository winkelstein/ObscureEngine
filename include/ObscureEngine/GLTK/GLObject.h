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

    protected:
      virtual bool isBinded() = 0;

    public:
      virtual void bind() = 0;
      virtual void unbind() = 0;
    };
  }
}