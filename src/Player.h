#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"

class Player : public GameObject
{
  public:
    Player() = default;
    Player(int x, int y, sf::Texture text) : GameObject(x, y, text)
    {
    }

    void update(float dt) override;
    void animate();

  private:
    sf::Texture texture_atlas;
};

#endif
