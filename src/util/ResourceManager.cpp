#include "ResourceManager.h"

std::map<std::string, sf::Texture *> ResourceManager::texture_map;
std::map<std::string, sf::Font *> ResourceManager::font_map;
std::map<std::string, sf::SoundBuffer *> ResourceManager::sound_map;

const std::vector<std::string> ResourceManager::TEXTURE_FILE_EXTENSIONS = {"png", "jpg", "jpeg"};
const std::vector<std::string> ResourceManager::FONT_FILE_EXTENSIONS = {"ttf"};
const std::vector<std::string> ResourceManager::SOUND_FILE_EXTENSIONS = {"wav"};

sf::Texture *ResourceManager::get_texture(const std::string &filepath)
{
    // Check if already present
    for (auto b = texture_map.begin(); b != texture_map.end(); ++b)
    {
        if (b->first == filepath)
        {
            std::cout << "Texture already loaded\n";
            return b->second;
        }
    }

    sf::Texture *texture = new sf::Texture();

    if (!texture->loadFromFile(filepath))
    {
        std::cerr << "Failed to load texture at " << filepath << std::endl;
        return nullptr;
    }
    std::cout << "Texture loaded at " << filepath << std::endl;

    texture_map[filepath] = texture;

    return texture_map[filepath];
}

void ResourceManager::preload_textures(const std::string &folder, bool recursive)
{
    if (recursive)
    {
        for (auto &file : std::filesystem::recursive_directory_iterator(folder))
        {
            std::stringstream ss;
            ss << file;
            std::cout << ss.str() << std::endl;
            if (contains(ss.str().substr(ss.str().length() - 4, 3), TEXTURE_FILE_EXTENSIONS))
            // if (contains(ss.str().substr(ss.str().find(".") + 1), TEXTURE_FILE_EXTENSIONS))
            {
                sf::Texture *texture = new sf::Texture();

                if (!(texture->loadFromFile(ss.str().substr(1, ss.str().length() - 2))))
                {
                    std::cerr << "Failed to load Texture at " << ss.str() << std::endl;
                    continue;
                }
                texture_map[ss.str().substr(1, ss.str().length() - 2)] = texture;
                std::cout << "Loaded texture " << ss.str() << std::endl;
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
            // if (contains(ss.str().substr(ss.str().find(".") + 1), TEXTURE_FILE_EXTENSIONS))
            {
                sf::Texture *texture = new sf::Texture();

                if (!(texture->loadFromFile(ss.str().substr(1, ss.str().length() - 2))))
                {
                    std::cerr << "Failed to load Texture at " << ss.str() << std::endl;
                    continue;
                }
                texture_map[ss.str().substr(1, ss.str().length() - 2)] = texture;
                std::cout << "Loaded texture " << ss.str() << std::endl;
            }
        }
    }
}

size_t ResourceManager::get_texture_count()
{
    return texture_map.size();
}

sf::Font *ResourceManager::get_font(const std::string &filepath)
{
    for (auto b = font_map.begin(); b != font_map.end(); ++b)
    {
        if (b->first == filepath)
        {
            return b->second;
        }
    }

    sf::Font *font = new sf::Font();

    if (!font->openFromFile(filepath))
    {
        std::cerr << "Failed to load font at " << filepath << std::endl;
        return nullptr;
    }

    font_map[filepath] = font;

    return font_map[filepath];
}

void ResourceManager::preload_fonts(const std::string &folder, bool recursive)
{
    if (recursive)
    {
        for (auto &file : std::filesystem::recursive_directory_iterator(folder))
        {
            std::stringstream ss;
            ss << file;
            if (contains(ss.str().substr(ss.str().find(".") + 1), FONT_FILE_EXTENSIONS))
            {
                sf::Font *font = new sf::Font();

                if (!(font->openFromFile(ss.str().substr(1, ss.str().length() - 2))))
                {
                    std::cerr << "Failed to load font at " << ss.str() << std::endl;
                    continue;
                }
                font_map[ss.str().substr(1, ss.str().length() - 2)] = font;
            }
        }
    }
    else
    {
        for (auto &file : std::filesystem::directory_iterator(folder))
        {
            std::stringstream ss;
            ss << file;
            if (contains(ss.str().substr(ss.str().find(".") + 1), FONT_FILE_EXTENSIONS))
            {
                sf::Font *font = new sf::Font();

                if (!(font->openFromFile(ss.str().substr(1, ss.str().length() - 2))))
                {
                    std::cerr << "Failed to load font at " << ss.str() << std::endl;
                    continue;
                }
                font_map[ss.str().substr(1, ss.str().length() - 2)] = font;
            }
        }
    }
}

size_t ResourceManager::get_font_count()
{
    return font_map.size();
}

sf::SoundBuffer *ResourceManager::get_soundbuffer(const std::string &filepath)
{
    for (auto b = sound_map.begin(); b != sound_map.end(); ++b)
    {
        if (b->first == filepath)
        {
            return b->second;
        }
    }

    sf::SoundBuffer *sound = new sf::SoundBuffer();

    if (!sound->loadFromFile(filepath))
    {
        std::cerr << "Failed to load sound at " << filepath << std::endl;
        return nullptr;
    }

    sound_map[filepath] = sound;

    return sound_map[filepath];
}

void ResourceManager::preload_soundbuffers(const std::string &folder, bool recursive)
{
    if (recursive)
    {
        for (auto &file : std::filesystem::recursive_directory_iterator(folder))
        {
            std::stringstream ss;
            ss << file;
            if (contains(ss.str().substr(ss.str().find(".") + 1), SOUND_FILE_EXTENSIONS))
            {
                sf::SoundBuffer *sound = new sf::SoundBuffer();

                if (!(sound->loadFromFile(ss.str().substr(1, ss.str().length() - 2))))
                {

                    std::cerr << "Failed to load Sound at " << ss.str() << std::endl;
                    continue;
                }
                sound_map[ss.str().substr(1, ss.str().length() - 2)] = sound;
            }
        }
    }
    else
    {
        for (auto &file : std::filesystem::directory_iterator(folder))
        {
            std::stringstream ss;
            ss << file;
            if (contains(ss.str().substr(ss.str().find(".") + 1), FONT_FILE_EXTENSIONS))
            {
                sf::SoundBuffer *sound = new sf::SoundBuffer();

                if (!(sound->loadFromFile(ss.str().substr(1, ss.str().length() - 2))))
                {

                    std::cerr << "Failed to load Sound at " << ss.str() << std::endl;
                    continue;
                }
                sound_map[ss.str().substr(1, ss.str().length() - 2)] = sound;
            }
        }
    }
}

size_t ResourceManager::get_sound_count()
{
    return sound_map.size();
}

void ResourceManager::clear_fonts()
{
    for (auto e : font_map)
    {
        delete e.second;
    }

    font_map.clear();
}

void ResourceManager::clear_sounds()
{
    for (auto e : sound_map)
    {
        delete e.second;
    }

    sound_map.clear();
}

void ResourceManager::clear_textures()
{
    for (auto e : texture_map)
    {
        delete e.second;
    }

    texture_map.clear();
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
