#include "GameObject.h"

void GameObject::update(float dt)
{
    update_func(dt);
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

void GameObject::move(int x, int y)
{
    pos.x += x;
    pos.y += y;
}

void GameObject::move(sf::Vector2i pos)
{
    this->pos.x = pos.x;
    this->pos.y = pos.y;
}
