#ifndef CAMERA_H
#define CAMERA_H

#include <SFML/Graphics.hpp>

#include "GameObject.h"
#include "Player.h"

#include <vector>

class Camera
{
  public:
    Camera(Player *plyr, std::vector<GameObject *> objs) : player(plyr), game_objs(&objs)
    {
        current_focus = player;
    }

    void set_focus(GameObject *obj);
    void move(sf::Vector2f vec);
    void move(float x, float y);

    void update(sf::Time dt);

  private:
    Player *player;
    std::vector<GameObject *> *game_objs;

    GameObject *current_focus;
};

#endif