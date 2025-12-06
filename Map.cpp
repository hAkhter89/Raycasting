#include "Headers/Map.h"

Map::Map(): mapWidth(24), mapHeight(24) {}

Map::Map(int h, int w) : mapWidth(w), mapHeight(h) {}

int Map::getMapWidth() const { return mapWidth; }

int Map::getMapHeight() const { return mapHeight; }

const std::vector<std::vector<int>>& Map::getGrid() const { return grid; }

// legacy function, not used currently
void Map::updateMap(int x, int y, int value) {
    if (x >= 0 && x < mapWidth && y >= 0 && y < mapHeight) {
        grid[y][x] = value; 
    }
}