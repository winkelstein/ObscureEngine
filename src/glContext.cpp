#include "../include/ObscureEngine/GLTK/glContext.h"

void ObscureEngine::GLTK::glContext::context_init(GLFWwindow *window)
{
  this->window = window;

  glEnable(GL_DEPTH_TEST);
  glEnable(GL_BLEND);

  glDepthFunc(GL_LESS);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void ObscureEngine::GLTK::glContext::context_destroy()
{
}

void ObscureEngine::GLTK::glContext::context_makeContextCurrent()
{
  glfwMakeContextCurrent(this->window);
}

void ObscureEngine::GLTK::glContext::context_swapBuffers()
{
  glfwSwapBuffers(this->window);
}

void ObscureEngine::GLTK::glContext::context_clear(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
  glClearColor(red, green, blue, alpha);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}