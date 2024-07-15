#pragma once
#include <chrono>

namespace ObscureEngine
{
  class FPSCounter
  {
  private:
    double m_ticks;

    std::chrono::high_resolution_clock::time_point time_point;

  public:
    FPSCounter() : m_ticks(0.1) {}

    void start();
    void stop();

    inline double ticks() const { return this->m_ticks; }
  };
}