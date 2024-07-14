#include "../include/ObscureEngine/GLTK/Shader.h"

GLuint ObscureEngine::GLTK::Shader::binded_program = 0;

ObscureEngine::GLTK::Shader::Shader(GLuint instance)
{
  this->instance = instance;
  this->getUniforms();
}

ObscureEngine::GLTK::Shader::~Shader()
{
  glDeleteProgram(this->instance);
}

void ObscureEngine::GLTK::Shader::bind()
{
  Shader::binded_program = this->instance;

  glUseProgram(this->instance);
}
void ObscureEngine::GLTK::Shader::unbind()
{
  Shader::binded_program = 0;

  glUseProgram(this->instance);
}

bool ObscureEngine::GLTK::Shader::isBinded() const
{
  bool result = false;

  if (Shader::binded_program == this->instance)
  {
    result = true;
  }

  return result;
}

void ObscureEngine::GLTK::Shader::getUniforms()
{
  int numUniforms = 0;
  glGetProgramiv(this->instance, GL_ACTIVE_UNIFORMS, &numUniforms);

  for (int i = 0; i < numUniforms; i++)
  {
    std::string name;
    name.resize(16);

    GLsizei length = 0;
    GLsizei var_size = 0;
    GLenum type = 0;
    glGetActiveUniform(this->instance, i, 16, &length, &var_size, &type, &name[0]);

    GLint location = glGetUniformLocation(this->instance, name.c_str());
    this->uniforms.insert_or_assign(name, location);
  }
}

std::optional<GLint> ObscureEngine::GLTK::Shader::findUniformLocation(std::string_view name) const
{
  std::optional<GLint> result = std::nullopt;
  auto iter = this->uniforms.find(std::string(name));

  if (iter != this->uniforms.end())
    result = iter->second;

  return result;
}