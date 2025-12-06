#ifndef SEEKER_H
#define SEEKER_H
#include "Enemy.h"

class Seeker : public Enemy {
private:
    bool alert;
    bool inRange;

public:
    Seeker();
    void updateAlert(bool newAlert);
    void updateRange(bool newInRange);

    void update(Player& player, const Map& map, float deltaTime) override;
    std::string getType() const override;
};

#endif