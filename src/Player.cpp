#include "Player.h"

Player::Player(float x, float y, sf::Texture *tex) : GameObject(x, y, tex)
{
    this->sprite = new sf::Sprite(*(this->tex));
    this->sprite->setOrigin(sf::Vector2f((this->tex->getSize().x) / 2, (this->tex->getSize().y) / 2));
    this->sprite->setScale(sf::Vector2f(3, 3));
    this->sprite->setPosition(sf::Vector2f(x, y));
}

void Player::update(float dt)
{
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(*(this->sprite), states);
}