#pragma once

#include "GameObject.h"
#include "util/Input.h"

#include <cmath>
#include <string>
#include <vector>

enum CollisionState
{
    NONE,
    UP,
    LEFT,
    DOWN,
    RIGHT
};

class Player : public GameObject
{
  public:
    Player() = default;
    Player(sf::Vector2f initial_pos, float speed, sf::Texture *text, bool movable = true);

    void update(sf::Time dt, std::vector<GameObject *> objs);

    void draw(sf::RenderTarget &target, sf::RenderStates states = sf::RenderStates::Default) const override;

    void setSpeed(float s);
    float getSpeed() const;

    void setMovable(bool mov);
    bool isMovable() const;

    ~Player()
    {
    }

  private:
    void animate();
    bool willCollide(sf::Vector2f movement, const std::vector<GameObject *> &objs);

    sf::Vector2f normalized(sf::Vector2f vec);

    sf::Vector2f velocity;
    float velo_magnitude;

    float speed;
    bool can_move;

    char direction; // Up, Right, Down, Left
    // sf::Sprite *sprite;
};
