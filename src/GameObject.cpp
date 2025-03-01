#include "GameObject.h"

void GameObject::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    if (!tex)
    {
        sf::RectangleShape rectangle(sf::Vector2f(width, height));
        rectangle.setFillColor(sf::Color::White);
        rectangle.setPosition(pos);
        target.draw(rectangle, states);
    }
    target.draw(*this, states);
}

void GameObject::set_pos(float x, float y)
{
    pos.x = x;
    pos.y = y;
}

void GameObject::set_pos(sf::Vector2f pos)
{
    this->pos = pos;
}

void GameObject::move(float x, float y)
{
    pos.x += x;
    pos.y += y;
}

void GameObject::move(sf::Vector2f pos)
{
    this->pos.x = pos.x;
    this->pos.y = pos.y;
}

sf::Vector2f GameObject::get_pos() const
{
    return pos;
}