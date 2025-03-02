#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"

#include <optional>
#include <string>

class Player : public GameObject
{
  public:
    Player() = default;
    Player(float x, float y, sf::Texture *text);

    void update(float dt);

    void draw(sf::RenderTarget &target, sf::RenderStates states = sf::RenderStates::Default) const override;

    ~Player()
    {
    }

  private:
    void animate();

    char direction; // Up, Right, Down, Left
    // sf::Sprite *sprite;
};

#endif
