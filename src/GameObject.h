#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>

class GameObject : public sf::Sprite
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
    void move(int x, int y);
    void move(sf::Vector2i pos);

    void set_current_texture(sf::Texture);

    virtual void update(float);
    virtual void render(sf::RenderWindow &);

    inline sf::Vector2i get_pos()
    {
        return pos;
    };

    virtual ~GameObject() = default;

  private:
    sf::Texture tex;

  protected:
    sf::Vector2i pos;
};
#endif
