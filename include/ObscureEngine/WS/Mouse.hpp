#pragma once
#include "Window.h"

namespace ObscureEngine
{
  namespace WS
  {
    class Mouse
    {
    public:
      enum class MouseButton
      {
        Left = GLFW_MOUSE_BUTTON_LEFT,
        Right = GLFW_MOUSE_BUTTON_RIGHT,
        Middle = GLFW_MOUSE_BUTTON_MIDDLE,
      };

    public:
      inline static bool is_button_pressed(const Window &win, const MouseButton button);
      inline static bool is_button_released(const Window &win, const MouseButton button);
      inline static std::tuple<int, int> position(const Window &win);

      inline static void position(const Window &win, int width, int height);

      inline static void visibility(const Window &win, bool state);
    };
  }
}

bool ObscureEngine::WS::Mouse::is_button_pressed(const Window &win, const MouseButton button)
{
  int state = glfwGetMouseButton(win.__get_native_handler(), (int)button);
  return state == GLFW_PRESS;
}

bool ObscureEngine::WS::Mouse::is_button_released(const Window &win, const MouseButton button)
{
  int state = glfwGetMouseButton(win.__get_native_handler(), (int)button);
  return state == GLFW_RELEASE;
}

std::tuple<int, int> ObscureEngine::WS::Mouse::position(const Window &win)
{
  double xpos, ypos;
  glfwGetCursorPos(win.__get_native_handler(), &xpos, &ypos);
  auto [width, height] = win.size();
  if (xpos < 0 || xpos > width || ypos < 0 || ypos > height)
    return std::make_tuple(0, 0);
  return std::make_tuple(xpos, ypos);
}

void ObscureEngine::WS::Mouse::position(const Window &win, int width, int height)
{
  glfwSetCursorPos(win.__get_native_handler(), width, height);
}

void ObscureEngine::WS::Mouse::visibility(const Window &win, bool state)
{
  if (state)
    glfwSetInputMode(win.__get_native_handler(), GLFW_CURSOR, GLFW_CURSOR_NORMAL);
  else
    glfwSetInputMode(win.__get_native_handler(), GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
}