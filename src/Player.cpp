#include "Player.h"

Player::Player(sf::Vector2f initial_pos, float nspeed, sf::Texture *text, bool movable)
    : GameObject(initial_pos, text), velocity(0, 0), velo_magnitude(0), speed(nspeed / 100), can_move(movable),
      direction('r')
{
    this->sprite = new sf::Sprite(*(this->tex));
    this->sprite->setOrigin(sf::Vector2f((this->tex->getSize().x) / 2, (this->tex->getSize().y) / 2));
    this->sprite->setScale(sf::Vector2f(3, 3));
    this->sprite->setPosition(initial_pos);
}

void Player::update(sf::Time dt, std::vector<GameObject *> objs)
{
    if (can_move)
    {
        if (Input::is_key_down(sf::Keyboard::Key::W))
        {
            direction = 'u';
            velocity.y = -speed;
        }
        if (Input::is_key_down(sf::Keyboard::Key::A))
        {
            direction = 'l';
            velocity.x = -speed;
        }
        if (Input::is_key_down(sf::Keyboard::Key::S))
        {
            direction = 'd';
            velocity.y = speed;
        }
        if (Input::is_key_down(sf::Keyboard::Key::D))
        {
            direction = 'r';
            velocity.x = speed;
        }
    }

    if (direction != 'r' && direction != 'u' && direction != 'l' && direction != 'd')
        direction = 'r';

    sf::Vector2f movement = normalized(velocity) * static_cast<float>(dt.asMilliseconds());

    // Check for collisions before moving
    if (!will_collide(movement, objs))
    {
        move(movement);
    }

    velocity.x = 0;
    velocity.y = 0;
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
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

void Player::set_speed(float s)
{
    this->speed = s;
}

float Player::get_speed() const
{
    return this->speed;
}

void Player::set_movable(bool mov)
{
    this->can_move = mov;
}

bool Player::is_movable() const
{
    return this->can_move;
}

sf::Vector2f Player::normalized(sf::Vector2f vec)
{
    if (velocity.x != 0 || velocity.y != 0)
    {
        velo_magnitude = std::sqrt(this->velocity.x * this->velocity.x + this->velocity.y * this->velocity.y);
        return (vec / velo_magnitude) * speed;
    }
    else
    {
        return sf::Vector2f();
    }
}

bool Player::will_collide(sf::Vector2f movement, const std::vector<GameObject *> &objs)
{
    sf::FloatRect future_bounds = this->sprite->getGlobalBounds();
    future_bounds.position.x += movement.x;
    future_bounds.position.y += movement.y;

    for (const auto &e : objs)
    {
        if (future_bounds.findIntersection(e->get_sprite()->getGlobalBounds()))
        {
            return true;
        }
    }
    return false;
}