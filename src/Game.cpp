#include "Game.h"

void Game::init()
{
    window = new sf::RenderWindow(sf::VideoMode({800u, 640u}), "Game", sf::Style::Resize | sf::Style::Close);
    window->setFramerateLimit(60);

    // To Do fix file paths on windows
    ResourceManager::preloadTextures("res");
    player = new Player(sf::Vector2f(500, 500), 25, ResourceManager::getTexture("res/player.png"), &gameobjs);
    test = new GameObject(sf::Vector2f(200, 200), ResourceManager::getTexture("res/idk.png"));
    test->drawHitbox(true);
    player->drawHitbox(true);

    level = new Level(ResourceManager::getTexture("res/world/grass.png"), 32, 25, 20);

    // gameobjs.push_back(player);
    gameobjs.push_back(test);
}

void Game::run()
{
    while (window->isOpen())
    {
        processEvents();
        update();
        render();
    }
}

void Game::update()
{
    deltatime = deltaclock.restart();
    player->update(deltatime, gameobjs);
}

void Game::processEvents()
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

    level->draw(*(this->window));

    for (auto &e : gameobjs)
    {

        e->draw(*(this->window));
    }

    player->draw(*(this->window));

    window->display();
}
