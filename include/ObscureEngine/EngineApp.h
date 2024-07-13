#pragma once
#include "WS/Window.h"
#include <optional>

namespace ObscureEngine
{
  class EngineApp
  {
  protected:
    WS::Window window;

  public:
    virtual void run() = 0;
  };
}