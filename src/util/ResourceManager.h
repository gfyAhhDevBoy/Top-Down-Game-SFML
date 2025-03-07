#pragma once

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
    static sf::Texture *getTexture(const std::string &filepath);
    inline static size_t getTextureCount();
    static void preloadTextures(const std::string &folder, bool recursive = true);

    static sf::SoundBuffer *getSoundbuffer(const std::string &filepath);
    inline static size_t getSoundCount();
    static void preloadSoundbuffers(const std::string &folder, bool recursive = true);

    static sf::Font *getFont(const std::string &filepath);
    inline static size_t getFontCount();
    static void preloadFonts(const std::string &folder, bool recursive = true);

    inline static void clearTextures();
    inline static void clearFonts();
    inline static void clearSounds();

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