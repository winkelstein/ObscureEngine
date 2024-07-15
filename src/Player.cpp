#include "../include/ObscureEngine/Player.h"

void ObscureEngine::Player::onMouseInput(const ObscureEngine::WS::Window &window)
{
  using ObscureEngine::WS::Mouse;

  static float pitch, yaw;

  auto [win_width, win_height] = window.size();
  auto [mouse_x, mouse_y] = Mouse::position(window);
  float xoff = ((int64_t)mouse_x - (int64_t)(win_width / 2.0));
  float yoff = ((int64_t)(win_height / 2.0) - (int64_t)mouse_y);

  yaw += xoff * this->sensitive;
  pitch += yoff * this->sensitive;

  if (pitch > 85.0)
    pitch = 85.0;
  else if (pitch < -85.0)
    pitch = -85.0;

  this->m_camera.rotate(glm::radians(yaw), glm::radians(pitch));
}

void ObscureEngine::Player::onKeyboardInput(const ObscureEngine::WS::Window &window)
{
  using ObscureEngine::WS::Keyboard;

  this->velocity.x = ((1.0 * Keyboard::isButtonPressed(window, Keyboard::VirtualKey::W) + (-1.0 * Keyboard::isButtonPressed(window, Keyboard::VirtualKey::S))));
  this->velocity.z = ((1.0 * Keyboard::isButtonPressed(window, Keyboard::VirtualKey::D) + (-1.0 * Keyboard::isButtonPressed(window, Keyboard::VirtualKey::A))));
  this->velocity.y = ((1.0 * Keyboard::isButtonPressed(window, Keyboard::VirtualKey::Space)) + (-1.0 * Keyboard::isButtonPressed(window, Keyboard::VirtualKey::LeftCtrl)));

  if (Keyboard::isButtonPressed(window, Keyboard::VirtualKey::LeftShift))
    this->velocity *= 2;
}

void ObscureEngine::Player::process(double ticks)
{
  float speed = this->speed * ticks / Physics::constants::TICK_COEF;

  this->move(speed * this->velocity);
}

void ObscureEngine::Player::move(glm::vec3 velocity)
{
  glm::vec3 position = this->m_camera.position();
  glm::vec3 front = this->m_camera.front();

  // front.y = 0.0;

  position += glm::normalize(front) * velocity.x;
  position += glm::normalize(glm::cross(front, glm::vec3(0.0, 1.0, 0.0))) * velocity.z;
  // position += glm::normalize(glm::cross(front, glm::cross(front, glm::vec3(0.0, 1.0, 0.0)))) * (-velocity.y);
  position += glm::vec3(0.0, 1.0, 0.0) * velocity.y;

  this->m_camera.position(position);
}