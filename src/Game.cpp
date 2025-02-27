#include "Game.h"

void Game::init()
{
    window.create(sf::VideoMode({800u, 600u}), "Game");

    window.setFramerateLimit(60);

    sf::Texture texture;
    if (!texture.loadFromFile("res/test.png"))
    {
    }

    test = new GameObject(100, 100, texture);
}

void Game::run()
{
    while (window.isOpen())
    {
        process_events();
        update();
        render();
    }
}

void Game::update()
{
}

void Game::process_events()
{
    while (const std::optional event = window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
        {
            window.close();
        }
        else if (const auto *keyPressed = event->getIf<sf::Event::KeyPressed>())
        {
            if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                window.close();
        }
    }
}

void Game::render()
{
    this->window.clear(sf::Color::Black);

    test->render(this->window);

    this->window.display();
}