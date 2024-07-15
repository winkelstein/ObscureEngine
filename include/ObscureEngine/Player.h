#pragma once
#include "Camera.h"
#include "WS/Window.h"
#include "WS/Keyboard.hpp"
#include "WS/Mouse.hpp"
#include "Physics/constants.h"

namespace ObscureEngine
{
  class Player
  {
  private:
    Camera m_camera;

    float speed;
    glm::vec3 velocity;

    float sensitive;

  public:
    Player() : speed(5.0), velocity(glm::vec3(0.0)), sensitive(0.1) {}

    void onMouseInput(const WS::Window &window);
    void onKeyboardInput(const WS::Window &window);

    virtual void process(double ticks);

    inline const Camera &camera() const { return this->m_camera; }

  private:
    void move(glm::vec3 velocity);
  };
}