#ifndef RESOURCE_H
#define RESOURCE_H

#include <SFML/Graphics.hpp>

#include <filesystem>
#include <iostream>
#include <map>
#include <string>
#include <vector>

class ResourceManager
{
    static std::map<std::string, sf::Texture *> texture_map;
    static std::map<std::string, sf::Font *> font_map;

  public:
    static sf::Texture *get_texture(std::string &);

    static void preload_textures(std::string &folder, bool recursive = true);

    ResourceManager() = delete;

  private:
    static const std::vector<std::string> TEXTURE_FILE_EXTENSIONS;
    static const std::vector<std::string> FONT_FILE_EXTENSIONS;

    static bool contains(std::string str, std::vector<std::string> vec);
};

#endif
