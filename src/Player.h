#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include "util/Input.h"

#include <cmath>
#include <string>
#include <vector>

class Player : public GameObject
{
  public:
    Player() = default;
    Player(float x, float y, float speed, sf::Texture *text, std::vector<GameObject *> *objs, bool movable = true);

    void update(sf::Time dt);

    void draw(sf::RenderTarget &target, sf::RenderStates states = sf::RenderStates::Default) const override;

    void set_speed(float s);
    float get_speed() const;

    void set_movable(bool mov);
    bool is_movable() const;

    ~Player()
    {
    }

  private:
    void animate();

    sf::Vector2f normalized(sf::Vector2f vec);

    sf::Vector2f velocity;
    float velo_magnitude;

    std::vector<GameObject *> *objs;

    float speed;
    bool can_move;

    char direction; // Up, Right, Down, Left
    // sf::Sprite *sprite;
};

#endif
