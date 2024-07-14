#include <iostream>
#include <ObscureEngine/WS/Window.h>
#include <ObscureEngine/GLTK/Shader.h>
#include <ObscureEngine/Importer/ShaderImporter.h>
#include <ObscureEngine/Voxel.h>

using ObscureEngine::Voxel;
using ObscureEngine::GLTK::Shader;
using ObscureEngine::Importer::ShaderImporter;
using ObscureEngine::WS::Window;

int main()
{
  Window window("ObscureEngine example", 800, 600);
  ShaderImporter shader_importer;

  auto shader_pair = shader_importer.import("assets/shaders/default");
  std::shared_ptr<Shader> shader = shader_pair.second;
  shader->bind();

  while (window.isOpen())
  {
    window.pollEvent();

    window.clear(1.0, 1.0, 1.0, 1.0);
  }
}