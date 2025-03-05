#include "GameObject.h"

void GameObject::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    if (hitbox)
    {
        sf::RectangleShape rect(sf::Vector2f(sprite->getGlobalBounds().size.x, sprite->getGlobalBounds().size.y));
        rect.setPosition(sf::Vector2f(sprite->getGlobalBounds().position.x, sprite->getGlobalBounds().position.y));
        rect.setFillColor(sf::Color::Transparent);
        rect.setOutlineColor(sf::Color::Red);
        rect.setOutlineThickness(2.0f);
        target.draw(rect);
    }

    target.draw(*(this->sprite), states);
}

void GameObject::set_pos(float x, float y)
{
    this->sprite->setPosition(sf::Vector2f(x, y));
}

void GameObject::set_pos(sf::Vector2f pos)
{
    this->sprite->setPosition(pos);
}

void GameObject::move(float x, float y)
{
    this->sprite->move(sf::Vector2f(x, y));
}

void GameObject::move(sf::Vector2f pos)
{
    this->sprite->move(pos);
}

sf::Vector2f GameObject::get_pos() const
{
    return this->sprite->getPosition();
}

bool GameObject::can_collide() const
{
    return collidable;
}

sf::Sprite *GameObject::get_sprite() const
{
    return sprite;
}

void GameObject::draw_hitbox(bool b)
{
    hitbox = b;
}