#include "Level.h"

Level::Level(sf::Texture *tile, int tSize, int tilesX, int tilesY) : tileset(tile), tileSize(tSize), tileCountX(tilesX), tileCountY(tilesY)
{
    int width = tile->getSize().x, height = tile->getSize().y;
    int tileCount = (width * height) / (tSize * tSize);
    if (tileCount % 2 != 0)
    {
        std::cerr << "Wrong size\n";
        return;
    }

    for (int i = 0; i < (tileCountY / 2); i++)
    {
        std::vector<sf::Sprite> tempVec;
        for (int s = 0; s < (tileCountX / 2); s++)
        {
            sf::Sprite tempSprite(*tileset);
            tempSprite.setPosition({s * tileCountX, i * tileCountY});
            tempSprite.setTextureRect(sf::IntRect({s * tileCountX, i * tileCountY}, {tileSize, tileSize}));
            tempVec.push_back(tempSprite);
        }
        tiles.push_back(tempVec);
    }

    std::cout << "init\n";
}

void Level::draw(sf::RenderTarget &target, sf::RenderStates states)
{
    for (int v = 0; v < tiles.size(); v++)
    {
        for (int s = 0; s < tiles[v].size(); s++)
        {
            target.draw(tiles[v][s], states);
        }
    }
}