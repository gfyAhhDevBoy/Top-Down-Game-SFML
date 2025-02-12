#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

enum Entity_type {
  ENTITY_INTERACTABLE,
  ENTITY_STATIC,
};

class Entity : sf::Sprite {
 public:
  Entity() = default;
  Entity(Entity_type entity_type, std::string &path, sf::Vector2i initial_pos)
      : type(entity_type), position(initial_pos) {
    load_texture(path);
  }

  void set_position(sf::Vector2i pos);
  void set_position(int x, int y);

  void update();
  void draw(sf::RenderTarget &target);

 private:
  void load_texture(std::string &path);

  Entity_type type;

  sf::Vector2i position;
  sf::Texture tex;
};