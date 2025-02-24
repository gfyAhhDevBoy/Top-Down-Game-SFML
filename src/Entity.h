#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Entity : sf::Sprite {
 public:
  Entity() = default;
  Entity(std::string &path, sf::Vector2i initial_pos)
      : position(initial_pos) {
    load_texture(path);
  }

  void set_position(sf::Vector2i pos);
  void set_position(int x, int y);

  void update();
  void draw(sf::RenderTarget &target);

 private:
  void load_texture(std::string &path);
  sf::Vector2i position;
  sf::Texture tex;
};
#endif