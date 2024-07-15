#include "../include/ObscureEngine/FPSCounter.h"

void ObscureEngine::FPSCounter::start()
{
  this->time_point = std::chrono::high_resolution_clock::now();
}

void ObscureEngine::FPSCounter::stop()
{
  auto end = std::chrono::high_resolution_clock::now();

  this->m_ticks = std::chrono::duration_cast<std::chrono::nanoseconds>(end - this->time_point).count();
}