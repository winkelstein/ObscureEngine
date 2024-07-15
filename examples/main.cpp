#include <iostream>
#include <ObscureEngine/WS/Window.h>
#include <ObscureEngine/GLTK/Shader.h>
#include <ObscureEngine/Importer/ShaderImporter.h>
#include <ObscureEngine/Voxel.h>
#include <ObscureEngine/Screen.h>
#include <ObscureEngine/Player.h>
#include <ObscureEngine/WS/Mouse.hpp>
#include <ObscureEngine/WS/Keyboard.hpp>
#include <ObscureEngine/FPSCounter.h>
#include <ObscureEngine/Model.h>
#include <ObscureEngine/Importer/ModelImporter.h>

using ObscureEngine::FPSCounter;
using ObscureEngine::Model;
using ObscureEngine::Player;
using ObscureEngine::Screen;
using ObscureEngine::Voxel;
using ObscureEngine::GLTK::Shader;
using ObscureEngine::Importer::ModelImporter;
using ObscureEngine::Importer::ShaderImporter;
using ObscureEngine::WS::Keyboard;
using ObscureEngine::WS::Mouse;
using ObscureEngine::WS::Window;

int main()
{
  Window window("ObscureEngine example", 800, 600);
  auto [width, height] = window.size();
  Player player;
  std::cout << (float)width << " " << (float)height << std::endl;
  Screen screen(width, height);
  FPSCounter counter;

  ShaderImporter shader_importer;
  ModelImporter model_importer;

  auto shader_pair = shader_importer.import("assets/shaders/default");
  std::shared_ptr<Shader> shader = shader_pair.second;
  shader->bind();

  auto model_pair = model_importer.import("assets/models/deer");
  std::shared_ptr<Model> deer = model_pair.second;

  while (window.isOpen())
  {
    counter.start();
    window.pollEvent();

    player.onMouseInput(window);
    auto [width, height] = window.size();
    Mouse::position(window, width / 2.0, height / 2.0);
    player.onKeyboardInput(window);
    player.process(counter.ticks());

    if (Keyboard::isButtonPressed(window, Keyboard::VirtualKey::ESC))
    {
      window.close();
    }

    screen.push(&*deer, *shader);
    screen.onCameraUpdate(player.camera());
    screen.render();
    window.clear(1.0, 1.0, 1.0, 1.0);
    counter.stop();
  }
}