#include "GameObject.h"

void GameObject::update(float dt)
{
}

void GameObject::render(sf::RenderWindow &target)
{
    target.draw(*this);
}

void GameObject::set_pos(int x, int y)
{
    pos.x = x;
    pos.y = y;
}

void GameObject::set_pos(sf::Vector2i pos)
{
    this->pos = pos;
}