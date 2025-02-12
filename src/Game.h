#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Entity.h"
#include "util/Input.h"

class Game {
  typedef sf::Keyboard::Key Keys;

 public:
  void init();
  void update();
  void render();

  bool should_close();

 private:
  void process_events();

  sf::RenderWindow window;
};
#endif