#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>

class GameObject : sf::Sprite
{
  public:
    GameObject(sf::Vector2i initial_pos, sf::Texture text) : pos(initial_pos), tex(text), sf::Sprite(tex)
    {
    }

    GameObject(int x, int y, sf::Texture text) : pos(x, y), tex(text), sf::Sprite(tex)
    {
    }

    void set_pos(int x, int y);
    void set_pos(sf::Vector2i pos);

    void update(float);
    void render(sf::RenderWindow &);

    inline sf::Vector2i get_pos()
    {
        return pos;
    };

  private:
    sf::Texture tex;
    sf::Vector2i pos;
};
#endif
