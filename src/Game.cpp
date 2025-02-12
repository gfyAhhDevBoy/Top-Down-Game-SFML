#include "Game.h"

void Game::init() {
  window.create(sf::VideoMode({800u, 600u}), "Game");
  window.setFramerateLimit(60);
}

void Game::update() { process_events(); }

void Game::process_events() {
  while (const std::optional event = window.pollEvent()) {
    if (event->is<sf::Event::Closed>()) {
      window.close();
    }
  }
}

void Game::render() {
  window.clear();

  window.display();
}

bool Game::should_close() { return !window.isOpen(); }