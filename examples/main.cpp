#include <iostream>
#include <ObscureEngine/WS/Window.h>
#include <ObscureEngine/GLTK/Shader.h>
#include <ObscureEngine/Importer/ShaderImporter.h>
#include <ObscureEngine/Voxel.h>
#include <ObscureEngine/Screen.h>
#include <ObscureEngine/Camera.h>

using ObscureEngine::Camera;
using ObscureEngine::Screen;
using ObscureEngine::Voxel;
using ObscureEngine::GLTK::Shader;
using ObscureEngine::Importer::ShaderImporter;
using ObscureEngine::WS::Window;

int main()
{
  Window window("ObscureEngine example", 800, 600);
  auto [width, height] = window.size();
  Screen screen(width, height);
  Camera camera;

  ShaderImporter shader_importer;

  auto shader_pair = shader_importer.import("assets/shaders/default");
  std::shared_ptr<Shader> shader = shader_pair.second;
  shader->bind();

  Voxel vox1(glm::vec4(1.0, 0.0, 0.0, 1.0));
  vox1.position(glm::vec3(0.0, 0.0, -5.0));

  while (window.isOpen())
  {
    window.pollEvent();

    screen.push(&vox1, *shader);
    screen.onCameraUpdate(camera);
    screen.render();
    window.clear(1.0, 1.0, 1.0, 1.0);
  }
}