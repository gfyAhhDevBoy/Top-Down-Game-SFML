#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"

class Player : public GameObject
{
  public:
    Player() = default;
    Player(int x, int y, sf::Texture text, int framew, int frameh, int n)
        : GameObject(x, y, text), texture_atlas(text), frame_height(frameh), frame_width(framew), frames(n)
    {
        texture_height = texture_atlas.getSize().y;
        texture_width = texture_atlas.getSize().x;
    }

    void update(float dt) override;
    void animate();

  private:
    int texture_height, texture_width, frame_height, frame_width, frames;
    sf::Texture texture_atlas;
};

#endif // !PLAYER_H
