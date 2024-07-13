#pragma once
#include "GLObject.h"
#include <glm/glm.hpp>
#include <map>
#include <string_view>

namespace ObscureEngine
{
  namespace GLTK
  {
    class Shader : public GLObject
    {
    private:
      static GLuint binded_program;
      std::map<const std::string, GLint> uniforms;

    public:
      enum class ShaderType
      {
        vertex = GL_VERTEX_SHADER,
        fragment = GL_FRAGMENT_SHADER,
        geometry = GL_GEOMETRY_SHADER,
        tess_control = GL_TESS_CONTROL_SHADER,
        tess_evaluation = GL_TESS_EVALUATION_SHADER,
      };

    public:
      Shader(GLuint instance);
      ~Shader();

      void bind() override;
      void unbind() override;
      bool isBinded() const override;

      template <class _Ty>
      void uniform(std::string_view name, _Ty data);

    private:
      void getUniforms();
      std::optional<GLint> findUniformLocation(std::string_view name) const;
    };
  }
}

template <>
inline void ObscureEngine::GLTK::Shader::uniform<int>(std::string_view name, int data)
{
  std::optional<GLint> location = this->findUniformLocation(name);

  if (location.has_value())
    glUniform1i(location.value(), data);
  else
    throw std::runtime_error("Specified uniform does not exist");
}

template <>
inline void ObscureEngine::GLTK::Shader::uniform<float>(std::string_view name, float data)
{
  std::optional<GLint> location = this->findUniformLocation(name);

  if (location.has_value())
    glUniform1f(location.value(), data);
  else
    throw std::runtime_error("Specified uniform does not exist");
}

template <>
inline void ObscureEngine::GLTK::Shader::uniform<glm::vec3>(std::string_view name, glm::vec3 data)
{
  std::optional<GLint> location = this->findUniformLocation(name);

  if (location.has_value())
    glUniform3fv(location.value(), 1, &data[0]);
  else
    throw std::runtime_error("Specified uniform does not exist");
}

template <>
inline void ObscureEngine::GLTK::Shader::uniform<glm::vec4>(std::string_view name, glm::vec4 data)
{
  std::optional<GLint> location = this->findUniformLocation(name);

  if (location.has_value())
    glUniform4fv(location.value(), 1, &data[0]);
  else
    throw std::runtime_error("Specified uniform does not exist");
}

template <>
inline void ObscureEngine::GLTK::Shader::uniform<glm::mat4>(std::string_view name, glm::mat4 data)
{
  std::optional<GLint> location = this->findUniformLocation(name);

  if (location.has_value())
    glUniformMatrix4fv(location.value(), 1, GL_FALSE, &data[0][0]);
  else
    throw std::runtime_error("Specified uniform does not exist");
}