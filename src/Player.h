#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"

class Player : public GameObject
{
  public:
    Player() = default;
    Player(float x, float y, sf::Texture *text);

    void update(float dt);

  private:
    void animate();

    sf::Sprite sprite;
};

#endif
