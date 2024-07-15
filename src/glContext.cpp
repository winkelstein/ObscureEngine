#include "../include/ObscureEngine/GLTK/glContext.h"
#include <iostream>

void ObscureEngine::GLTK::glContext::context_init(GLFWwindow *window)
{
  this->window = window;
  this->context_makeContextCurrent();

  glEnable(GL_DEPTH_TEST);
  glEnable(GL_BLEND);

  glDepthMask(GL_TRUE);

  glDepthFunc(GL_LESS);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void ObscureEngine::GLTK::glContext::context_destroy() {}

void ObscureEngine::GLTK::glContext::context_makeContextCurrent()
{
  glfwMakeContextCurrent(this->window);
}

void ObscureEngine::GLTK::glContext::context_swapBuffers()
{
  glfwSwapBuffers(this->window);
}

void ObscureEngine::GLTK::glContext::context_clear(float red, float green, float blue, float alpha)
{
  glClearColor(red, green, blue, alpha);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}