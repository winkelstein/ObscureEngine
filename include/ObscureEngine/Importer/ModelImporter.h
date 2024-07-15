#pragma once
#include "Importer.h"
#include "../Model.h"

namespace ObscureEngine
{
  namespace Importer
  {
    class ModelImporter : public Importer<Model>
    {
      using ModelImporterType = std::pair<std::string, std::shared_ptr<Model>>;

      struct Config
      {
        std::string name;
        std::filesystem::path model;
      };

      struct SizeChunk
      {
        int32_t x, y, z;
      };

      struct VoxelFormat
      {
        unsigned char distance;
        unsigned char color;
        unsigned char shade;
        unsigned char index;
      };

      struct VoxPos
      {
        int x, y, z, colorIndex;
      };

      struct VoxSize
      {
        int sizeX, sizeY, sizeZ;
      };

    public:
      ModelImporterType import(std::filesystem::path path_to_config);

    private:
      std::shared_ptr<Model> readFromFile(std::filesystem::path path_to_config);
      std::shared_ptr<Model> parseModel(std::vector<VoxPos> positions, std::vector<VoxSize> sizes, std::vector<uint32_t> palette);
      std::vector<uint32_t> loadPalette(FILE *file, int total_size);
      Config parseConfig(std::filesystem::path path_to_config);
    };
  }
}