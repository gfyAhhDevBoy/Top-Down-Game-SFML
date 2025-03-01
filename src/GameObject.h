#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>

class GameObject : public sf::Drawable
{
  public:
    GameObject(sf::Vector2f initial_pos, sf::Texture *text) : pos(initial_pos), tex(text)
    {
        height = tex->getSize().y;
        width = tex->getSize().x;
    }

    GameObject(float x, float y, sf::Texture *text) : pos(x, y), tex(text)
    {
        height = tex->getSize().y;
        width = tex->getSize().x;
    }

    GameObject(float x, float y, int width, int height) : pos(x, y), width(width), height(height), tex(nullptr)
    {
    }

    GameObject(sf::Vector2f initial_pos, int width, int height)
        : pos(initial_pos), width(width), height(height), tex(nullptr)
    {
    }

    void set_pos(float x, float y);
    void set_pos(sf::Vector2f pos);
    void set_x(float x);
    void set_y(float y);
    void move(float x, float y);
    void move(sf::Vector2f pos);

    sf::Vector2f get_pos() const;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    virtual ~GameObject() = default;

  protected:
    int height, width;

    sf::Vector2f pos;
    sf::Texture *tex;
};
#endif
