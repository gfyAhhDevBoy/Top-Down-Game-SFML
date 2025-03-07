#include "Level.h"

Level::Level(sf::Texture *tile, int tSize) : tileset(tile), tileSize(tSize)
{
    int width = tile->getSize().x, height = tile->getSize().y;
    int tileCount = (width * height) / (tSize * tSize);
    if (tileCount % 2 != 0)
    {
        std::cerr << "Wrong size\n";
        return;
    }

    for (int i = 0; i < (tileCount / 2) - 1; i++)
    {
        std::vector<sf::Sprite> tempVec;
        for (int i = 0; i < (tileCount / 2) - 1; i++)
        {
            sf::Sprite tempSprite(*tileset);
            tempSprite.setPosition({i * tileSize, i * tileSize});
            tempSprite.setTextureRect(sf::IntRect({(i + 1) * tileSize, (i + 1) * tileSize}, {tileSize, tileSize}));
            tempVec.push_back(tempSprite);
        }
        tiles.push_back(tempVec);
    }
}

void Level::draw(sf::RenderTarget &target, sf::RenderStates states)
{
    for (int v = 0; v < tiles.size(); v++)
    {
        for (int s = 0; s < tiles[v].size(); v++)
        {
            std::cout << "gerge\n";
            target.draw(tiles[v][s], states);
        }
    }
}