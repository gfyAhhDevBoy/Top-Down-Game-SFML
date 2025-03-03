#ifndef CAMERA_H
#define CAMERA_H

#include "GameObject.h"
#include "Player.h"

#include <vector>

class Camera
{
  public:
    Camera(Player *plyr, std::vector<GameObject *> &objs) : player(plyr), game_objs(objs)
    {
    }

    void set_focus(GameObject *obj);
    void move(sf::Vector2f vec);
    void move(float x, float y);

  private:
    Player *player;
    std::vector<GameObject *> game_objs;

    GameObject *current_focus;
};

#endif