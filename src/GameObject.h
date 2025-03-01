#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>

typedef void (*update_callback_function)(float);

class GameObject : public sf::Sprite
{
  public:
    GameObject(sf::Vector2i initial_pos, sf::Texture text, update_callback_function ufunc)
        : pos(initial_pos), tex(text), sf::Sprite(tex), update_func(ufunc)
    {
    }

    GameObject(int x, int y, sf::Texture text, update_callback_function ufunc)
        : pos(x, y), tex(text), sf::Sprite(tex), update_func(ufunc)
    {
    }

    GameObject(int x, int y, sf::Texture text) : pos(x, y), tex(text)
    {
    }

    inline void set_pos(int x, int y);
    inline void set_pos(sf::Vector2i pos);
    inline void move(int x, int y);
    inline void move(sf::Vector2i pos);

    void set_current_texture(sf::Texture);

    inline void set_update_func(update_callback_function ufunc)
    {
        update_func = ufunc;
    };

    virtual void update(float);
    void render(sf::RenderWindow &);

    virtual ~GameObject() = default;

  protected:
    update_callback_function update_func;
    sf::Vector2i pos;

  private:
    sf::Texture tex;
};
#endif
