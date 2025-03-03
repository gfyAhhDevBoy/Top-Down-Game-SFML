#include "Game.h"

void Game::init()
{
    window = new sf::RenderWindow(sf::VideoMode({800u, 600u}), "Game", sf::Style::Resize | sf::Style::Close);
    window->setFramerateLimit(60);

    // To Do fix file paths on windows
    ResourceManager::preload_textures("res");
    player = new Player(500, 500, 25, ResourceManager::get_texture("res/player.png"));
    test = new GameObject(200, 200, ResourceManager::get_texture("res/idk.png"));

    // gameobjs.push_back(player);
    gameobjs.push_back(test);

    camera = new Camera(player, gameobjs);
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
    deltatime = deltaclock.restart();
    camera->update(deltatime);
    player->update(deltatime);
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

    player->draw(*(this->window));

    window->display();
}
