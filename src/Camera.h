#ifndef CAMERA_H
#define CAMERA_H

#include "Player.h"

class Camera
{
  public:
    Camera(Player *plyr) : player(plyr)
    {
    }

  private:
    Player *player;
};

#endif