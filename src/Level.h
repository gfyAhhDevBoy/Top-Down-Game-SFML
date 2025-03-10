#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>

class Level
{
  public:
    Level(sf::Texture *tileset, int tSize, int tilesX, int tilesY);

    void draw(sf::RenderTarget &target, sf::RenderStates states = sf::RenderStates::Default);

  private:
    sf::Texture *tileset;
    int tileSize, tileCountX, tileCountY;

    std::vector<std::vector<sf::Sprite>> tiles;
};