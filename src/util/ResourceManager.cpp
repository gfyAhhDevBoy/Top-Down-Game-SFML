#include "ResourceManager.h"

std::map<std::string, sf::Texture *> ResourceManager::texture_map;
std::map<std::string, sf::Font *> ResourceManager::font_map;

const std::vector<std::string> ResourceManager::TEXTURE_FILE_EXTENSIONS = {"png", "jpg", "jpeg"};

sf::Texture *ResourceManager::get_texture(std::string &filepath)
{
    // Check if already present
    for (auto e : texture_map)
    {
        if (e.first == filepath)
        {
            return e.second;
        }
    }

    sf::Texture *texture = new sf::Texture();

    if (!texture->loadFromFile(filepath))
    {
        std::cerr << "Failed to load texture at " << filepath << std::endl;
        return nullptr;
    }

    texture_map[filepath] = texture;

    return texture_map[filepath];
}

void ResourceManager::preload_textures(std::string &folder, bool recursive)
{
    if (recursive)
    {
        for (auto &file : std::filesystem::recursive_directory_iterator(folder))
        {
            std::stringstream ss;
            ss << file;
            if (contains(ss.str().substr(ss.str().length() - 4, 3), TEXTURE_FILE_EXTENSIONS))
            {
                sf::Texture *texture = new sf::Texture();

                texture->loadFromFile(ss.str().substr(1, ss.str().length() - 2));
                texture_map[ss.str().substr(1, ss.str().length() - 2)] = texture;
            }
        }
    }
    else
    {
        for (auto &file : std::filesystem::directory_iterator(folder))
        {
            std::stringstream ss;
            ss << file;
            if (contains(ss.str().substr(ss.str().length() - 4, 3), TEXTURE_FILE_EXTENSIONS))
            {
                sf::Texture *texture = new sf::Texture();

                texture->loadFromFile(ss.str().substr(1, ss.str().length() - 2));
                texture_map[ss.str().substr(1, ss.str().length() - 2)] = texture;
            }
        }
    }
}

bool ResourceManager::contains(std::string str, std::vector<std::string> vec)
{
    for (std::string e : vec)
    {
        if (e == str)
        {
            return true;
        }
    }

    return false;
}
