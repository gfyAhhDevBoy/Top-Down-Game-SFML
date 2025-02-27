#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>

class GameObject : sf::Sprite {
public:
  GameObject(sf::Vector2i initial_pos, sf::Texture text)
      : pos(initial_pos), tex(text) {}

private:
  sf::Texture tex;
  sf::Vector2i pos;

  void update();
  void render(sf::RenderTarget);
};
#endif
