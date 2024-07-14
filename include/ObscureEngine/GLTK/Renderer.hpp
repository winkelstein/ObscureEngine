#pragma once
#include "Core.h"

namespace ObscureEngine
{
    namespace GLTK
    {
        class Renderer
        {
        public:
            static void render()
            {
                glDrawArrays(GL_TRIANGLES, 0, 36);
            }
        };
    }
}