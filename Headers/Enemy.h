#ifndef ENEMY_H
#define ENEMY_H
#include "Entity.h"
#include "Player.h"

class Enemy : public Entity {
private:
    int range;
    int damage;
    int speed;

protected:
    Enemy();
    Enemy(int hp);
    inline static int count = 0;

public:
    // Getters for hidden properties
    int getRange() const;
    int getDamage() const;
    int getSpeed() const;
    int getCount() const;

    // Setters for hidden properties
    void setRange(int r);
    void setDamage(int d);
    void setSpeed(int s);

    void attack(Player &player, int dmg = 10);
    std::string getType() const override;

    bool collides(const sf::Vector2f &testPos, const Map &map) const override;
};

#endif
