#pragma once
#include "Shader.h"

namespace ObscureEngine
{
    namespace GLTK
    {
        class Drawable
        {
        public:
            virtual void draw(Shader &shader) const = 0;
        };
    }
}