#include "../include/ObscureEngine/Screen.h"

ObscureEngine::Screen::Screen(uint32_t width, uint32_t height)
{
  glViewport(0, 0, width, height);
  std::memset(&this->mvp, 0, sizeof(MVP));
  this->mvp.projection = glm::perspectiveFov(glm::radians(60.0f), (float)width, (float)height, 0.01f, 10000.0f);

  this->ubo.bind();
  this->ubo.bindBase(0);

  this->ubo.data(&this->mvp);
}

void ObscureEngine::Screen::render()
{
  std::lock_guard lock(this->mtx);
  this->ubo.bind();
  this->ubo.data(&this->mvp);

  while (!this->qDraw.empty())
  {
    this->qDraw.front().first->draw(this->qDraw.front().second);
    this->qDraw.pop();
  }
}

void ObscureEngine::Screen::push(const GLTK::Drawable *object, GLTK::Shader &shader)
{
  std::lock_guard lock(this->mtx);
  this->qDraw.push(std::pair<const GLTK::Drawable *, GLTK::Shader &>(object, shader));
}

void ObscureEngine::Screen::resize(uint32_t width, uint32_t height)
{
  glViewport(0, 0, width, height);
  this->mvp.projection = glm::perspectiveFov(glm::radians(60.0f), (float)width, (float)height, 0.01f, 100.0f);
}

void ObscureEngine::Screen::onCameraUpdate(const Camera &camera)
{
  this->mvp.camera_view = camera.view();
}