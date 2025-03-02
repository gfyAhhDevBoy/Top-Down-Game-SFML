#include "Game.h"

void Game::init()
{
    window = new sf::RenderWindow(sf::VideoMode({800u, 600u}), "Game", sf::Style::Resize | sf::Style::Close);
    window->setFramerateLimit(60);

<<<<<<< HEAD
    // ToDo fix preloading
=======
    // To Do fix file paths on windows
>>>>>>> 66522254f7aedd64837521be23da71a22a24d058
    ResourceManager::preload_textures("res");
    player = new Player(500, 500, ResourceManager::get_texture("res\\player.png"));
    test = new GameObject(200, 200, ResourceManager::get_texture("res/idk.png"));

    // gameobjs.push_back(player);
    gameobjs.push_back(test);
}

void Game::run()
{
    while (window->isOpen())
    {
        process_events();
        update();
        render();
    }
}

void Game::update()
{
    // player->update(deltatime);
}

void Game::process_events()
{
    while (const std::optional event = window->pollEvent())
    {
        if (event->is<sf::Event::Closed>())
        {
            window->close();
        }
        else if (const auto *keyPressed = event->getIf<sf::Event::KeyPressed>())
        {
            if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                window->close();
        }
    }
}

void Game::render()
{
    window->clear(sf::Color::Black);

    for (auto e : gameobjs)
    {
        e->draw(*(this->window));
    }

    window->display();
}
