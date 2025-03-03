#include "GameObject.h"

void GameObject::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    // if (!tex)
    // {
    //     sf::RectangleShape rectangle(sf::Vector2f(width, height));
    //     rectangle.setFillColor(sf::Color::White);
    //     rectangle.setPosition(pos);
    //     target.draw(rectangle, states);
    // }

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