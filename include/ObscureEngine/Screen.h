#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "GLTK/UniformBuffer.h"
#include "GLTK/Drawable.h"
#include "GLTK/Shader.h"
#include "Camera.h"
#include <queue>
#include <mutex>

namespace ObscureEngine
{
  struct MVP
  {
    glm::mat4 projection;
    glm::mat4 camera_view;
  };

  class Screen
  {
  private:
    GLTK::UniformBuffer<MVP> ubo;
    MVP mvp;

    std::queue<std::pair<const GLTK::Drawable *, GLTK::Shader &>> qDraw;
    std::recursive_mutex mtx;

  public:
    Screen(uint32_t width, uint32_t height);

    void render();
    void push(const GLTK::Drawable *object, GLTK::Shader &shader);

    void resize(uint32_t width, uint32_t height);
    void onCameraUpdate(const Camera &camera);
  };
}