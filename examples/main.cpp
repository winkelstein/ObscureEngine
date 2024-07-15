#include <iostream>
#include <ObscureEngine/WS/Window.h>
#include <ObscureEngine/GLTK/Shader.h>
#include <ObscureEngine/Importer/ShaderImporter.h>
#include <ObscureEngine/Voxel.h>
#include <ObscureEngine/Screen.h>
#include <ObscureEngine/Player.h>
#include <ObscureEngine/WS/Mouse.hpp>
#include <ObscureEngine/WS/Keyboard.hpp>

using ObscureEngine::Player;
using ObscureEngine::Screen;
using ObscureEngine::Voxel;
using ObscureEngine::GLTK::Shader;
using ObscureEngine::Importer::ShaderImporter;
using ObscureEngine::WS::Keyboard;
using ObscureEngine::WS::Mouse;
using ObscureEngine::WS::Window;

int main()
{
  Window window("ObscureEngine example", 800, 600);
  auto [width, height] = window.size();
  Player player;
  Screen screen(width, height);

  ShaderImporter shader_importer;

  auto shader_pair = shader_importer.import("assets/shaders/default");
  std::shared_ptr<Shader> shader = shader_pair.second;
  shader->bind();

  Voxel vox1(glm::vec4(1.0, 0.0, 0.0, 1.0));
  vox1.position(glm::vec3(0.0, 0.0, 0.0));

  while (window.isOpen())
  {
    window.pollEvent();

    player.onMouseInput(window);
    auto [width, height] = window.size();
    Mouse::position(window, width / 2.0, height / 2.0);
    player.onKeyboardInput(window);
    player.process(ObscureEngine::Physics::constants::TICK_COEF);

    if (Keyboard::isButtonPressed(window, Keyboard::VirtualKey::ESC))
    {
      window.close();
    }

    screen.push(&vox1, *shader);
    screen.onCameraUpdate(player.camera());
    screen.render();
    window.clear(1.0, 1.0, 1.0, 1.0);
  }
}