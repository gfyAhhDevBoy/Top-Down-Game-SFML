#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>

#include <iostream>

class GameObject : public sf::Drawable
{
  public:
    GameObject(sf::Vector2f initial_pos, sf::Texture *text, bool can_collide = true)
        : tex(text), sprite(new sf::Sprite(*text)), collidable(can_collide), hitbox(false)
    {
        this->height = tex->getSize().x;
        this->width = tex->getSize().y;
        this->sprite->setOrigin(sf::Vector2f((this->tex->getSize().x) / 2, (this->tex->getSize().y) / 2));
        this->sprite->setScale(sf::Vector2f(3, 3));
        this->sprite->setPosition(initial_pos);
    }

    GameObject(float x, float y, int width, int height) : width(width), height(height), tex(nullptr)
    {
    }

    GameObject(sf::Vector2f initial_pos, int width, int height) : width(width), height(height), tex(nullptr)
    {
    }

    void setPos(float x, float y);
    void setPos(sf::Vector2f pos);
    void setX(float x);
    void setY(float y);
    void move(float x, float y);
    void move(sf::Vector2f pos);

    sf::Vector2f getPos() const;
    bool canCollide() const;
    sf::Sprite *getSprite() const;

    void drawHitbox(bool b);

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states = sf::RenderStates::Default) const override;

    virtual ~GameObject()
    {
    }

  private:
    bool collidable;

  protected:
    int height, width;
    bool hitbox;

    sf::Texture *tex;
    sf::Sprite *sprite;
};
#endif
