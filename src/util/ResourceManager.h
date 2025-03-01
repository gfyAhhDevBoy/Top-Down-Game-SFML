#ifndef RESOURCE_H
#define RESOURCE_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <filesystem>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

class ResourceManager
{
  public:
    static sf::Texture *get_texture(std::string &filepath);
    inline static size_t get_texture_count();
    static void preload_textures(std::string &folder, bool recursive = true);

    static sf::SoundBuffer *get_soundbuffer(std::string &filepath);
    inline static size_t get_sound_count();
    static void preload_soundbuffers(std::string &folder, bool recursive = true);

    static sf::Font *get_font(std::string &filepath);
    inline static size_t get_font_count();
    static void preload_fonts(std::string &folder, bool recursive = true);

    inline static void clear_textures();
    inline static void clear_fonts();
    inline static void clear_sounds();

    ResourceManager() = delete;

  private:
    static const std::vector<std::string> TEXTURE_FILE_EXTENSIONS;
    static const std::vector<std::string> FONT_FILE_EXTENSIONS;
    static const std::vector<std::string> SOUND_FILE_EXTENSIONS;

    static std::map<std::string, sf::Texture *> texture_map;
    static std::map<std::string, sf::Font *> font_map;
    static std::map<std::string, sf::SoundBuffer *> sound_map;

    static bool contains(std::string str, std::vector<std::string> vec);
};

#endif