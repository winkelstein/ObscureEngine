#pragma once
#include "Voxel.h"
#include "GLTK/Shader.h"
#include "GLTK/Drawable.h"
#include <vector>
#include <memory>

namespace ObscureEngine
{
  class Model : public GLTK::Drawable
  {
  private:
    std::vector<std::shared_ptr<Voxel>> voxels;

  public:
    Model(std::vector<std::shared_ptr<Voxel>> voxels);

    void draw(GLTK::Shader &shader) const override;

    /*
    void position(glm::vec3 position);
    void size(glm::vec3 size);
    void rotate(glm::vec3 point, glm::vec3 angles);

    inline glm::vec3 position() const { return this->m_position; }
    inline glm::vec3 size() const { return this->m_size; }
    inline glm::vec3 rotate() const { return this->m_rotate; }
        */
  };
}