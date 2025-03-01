#include "Player.h"

Player::Player(float x, float y, sf::Texture *tex) : GameObject(x, y, tex)
{
    set_pos(x, y);
}

void Player::update(float dt)
{
}
