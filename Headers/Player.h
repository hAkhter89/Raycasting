#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Map.h"

class Player : public Entity {
private:
    float speed; 
    sf::Vector2f dir;   
    sf::Vector2f plane;
    
    // Friend functions for direction and plane
    friend sf::Vector2f getDir(const Player& player);
    friend void setDir(Player& player, sf::Vector2f d);
    friend sf::Vector2f getPlane(const Player& player);
    friend void setPlane(Player& player, sf::Vector2f p);

public:
    Player();
    
    // Movement
    void setSpeed(int newSpeed);
    float getSpeed() const;
    
    void damage(int dmg);
    void move(float deltaTime, const Map& map, const sf::Keyboard::Key forward, const sf::Keyboard::Key backward);
    void rotate(float deltaTime, const sf::Keyboard::Key left, const sf::Keyboard::Key right);

    bool collides(const sf::Vector2f& testPos, const Map& map) const override;
};

// Friend function implementations
// (idk why I made these friend functions, but we needed some for the project so its fine)
// inline is needed here to avoid multiple definitions of the function (as it is implemented in header files)
inline sf::Vector2f getDir(const Player& player) { return player.dir; }

inline void setDir(Player& player, sf::Vector2f d) { player.dir = d; }

inline sf::Vector2f getPlane(const Player& player) { return player.plane; }

inline void setPlane(Player& player, sf::Vector2f p) { player.plane = p; }

#endif