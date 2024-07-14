#pragma once
#include "Core.h"
#include "GLObject.h"

namespace ObscureEngine
{
  namespace GLTK
  {
    template <class _Ty>
    class UniformBuffer : public GLObject
    {
    public:
      UniformBuffer();
      ~UniformBuffer();

      void data(const _Ty *data);
      void bindBase(const uint32_t base) const;

      void bind() override;
      void unbind() override;
    };
  }
}

template <class _Ty>
ObscureEngine::GLTK::UniformBuffer<_Ty>::UniformBuffer()
{
  glGenBuffers(1, &this->instance);
  glBindBuffer(GL_UNIFORM_BUFFER, this->instance);
  glBufferData(GL_UNIFORM_BUFFER, sizeof(_Ty), nullptr, GL_DYNAMIC_DRAW);
}

template <class _Ty>
ObscureEngine::GLTK::UniformBuffer<_Ty>::~UniformBuffer()
{
  glDeleteBuffers(1, &this->instance);
}

template <typename _Ty>
void ObscureEngine::GLTK::UniformBuffer<_Ty>::data(const _Ty *data)
{
  glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(_Ty), data);
}

template <typename _Ty>
void ObscureEngine::GLTK::UniformBuffer<_Ty>::bindBase(const unsigned int base) const
{
  glBindBufferBase(GL_UNIFORM_BUFFER, base, this->instance);
}

template <typename _Ty>
void ObscureEngine::GLTK::UniformBuffer<_Ty>::bind()
{
  glBindBuffer(GL_UNIFORM_BUFFER, this->instance);
}

template <typename _Ty>
void ObscureEngine::GLTK::UniformBuffer<_Ty>::unbind()
{
  glBindBuffer(GL_UNIFORM_BUFFER, 0);
}