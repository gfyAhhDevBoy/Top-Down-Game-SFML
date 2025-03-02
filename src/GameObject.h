#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>

class GameObject : public sf::Drawable
{
  public:
    GameObject(sf::Vector2f initial_pos, sf::Texture *text) : tex(text), sprite(new sf::Sprite(*tex))
    {
        height = tex->getSize().y;
        width = tex->getSize().x;
        this->sprite->setOrigin(sf::Vector2f((this->tex->getSize().x) / 2, (this->tex->getSize().y) / 2));
        this->sprite->setScale(sf::Vector2f(3, 3));
        this->sprite->setPosition(initial_pos);
    }

    GameObject(float x, float y, sf::Texture *text) : tex(text), sprite(new sf::Sprite(*tex))
    {
        height = tex->getSize().y;
        width = tex->getSize().x;
        this->sprite->setOrigin(sf::Vector2f((this->tex->getSize().x) / 2, (this->tex->getSize().y) / 2));
        this->sprite->setScale(sf::Vector2f(3, 3));
        this->sprite->setPosition(sf::Vector2f(x, y));
    }

    GameObject(float x, float y, int width, int height) : width(width), height(height), tex(nullptr)
    {
    }

    GameObject(sf::Vector2f initial_pos, int width, int height) : width(width), height(height), tex(nullptr)
    {
    }

    void set_pos(float x, float y);
    void set_pos(sf::Vector2f pos);
    void set_x(float x);
    void set_y(float y);
    void move(float x, float y);
    void move(sf::Vector2f pos);

    sf::Vector2f get_pos() const;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states = sf::RenderStates::Default) const override;

    virtual ~GameObject()
    {
    }

  protected:
    int height, width;

    sf::Texture *tex;
    sf::Sprite *sprite;
};
#endif
