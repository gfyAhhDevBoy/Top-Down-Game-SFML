#include "Entity.h"

void Entity::load_texture(std::string &path) {
  if (!tex.loadFromFile(path)) {
    std::cerr << "Failed to load texture " << path << "1" << std::endl;
  }
}

void Entity::draw(sf::RenderTarget &window) { this->draw(window); }