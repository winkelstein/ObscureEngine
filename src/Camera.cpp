#include "../include/ObscureEngine/Camera.h"

ObscureEngine::Camera::Camera(glm::vec3 position) : m_position(position), m_front(glm::vec3(0.0, 0.0, -1.0)), m_view(0.0)
{
}

void ObscureEngine::Camera::rotate(float yaw, float pitch)
{
  this->m_front.x = cos(yaw);
  this->m_front.y = tan(pitch);
  this->m_front.z = sin(yaw);

  this->updateView();
}

void ObscureEngine::Camera::position(glm::vec3 position)
{
  this->m_position = position;

  this->updateView();
}

void ObscureEngine::Camera::move(glm::vec3 position)
{
  this->m_position += position;

  this->updateView();
}

void ObscureEngine::Camera::updateView()
{
  this->m_view = glm::lookAt(this->m_position, this->m_front + this->m_position, glm::vec3(0.0, 1.0, 0.0));
}
