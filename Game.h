#ifndef GAME_H
#define GAME_H
#include "Enemy.h"
#include "Map.h"
#include "Player.h"
#include "RaycastEngine.h"
#include "Seeker.h"

enum GameState { Menu, Playing, DeathScreen };
class Game {
public:
  sf::RenderWindow window;
  Player player;
  Map map;
  RaycastEngine raycast;

  GameState currentState;
  sf::Font font;
  sf::Text startText;
  sf::RectangleShape startButton;
  sf::Text deathText;
  sf::Text survivalText;
  sf::Clock deathTimer;
  sf::Clock gameTimer;
  float survivalTime;

  Game();
  ~Game();
  void close() { window.close(); }
  void run();

private:
  void initMap();
};

#endif
