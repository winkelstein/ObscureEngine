#pragma once
#include "Importer.h"
#include "../GLTK/Shader.h"
#include <vector>

namespace ObscureEngine
{
  namespace Importer
  {
    class ShaderImporter : public Importer<GLTK::Shader>
    {
      using ShaderImporterType = std::pair<std::string, std::shared_ptr<GLTK::Shader>>;

    public:
      ShaderImporterType import(std::filesystem::path path_to_config) override;

    private:
      static std::string getSourceFromFile(std::filesystem::path path);
      static GLuint compileShader(std::string src, GLTK::Shader::ShaderType type);
      static GLuint linkShaderProgram(std::vector<GLuint> shaders);
      static GLuint add(GLTK::Shader::ShaderType type, std::filesystem::path path);
    };
  }
}
