#include "Headers/Enemy.h"

int Enemy::getRange() const { return range; }

int Enemy::getDamage() const { return damage; }

int Enemy::getSpeed() const { return speed; }

int Enemy::getCount() const { return count; }

void Enemy::setRange(int r) { range = r; }

void Enemy::setDamage(int d) { damage = d; }

void Enemy::setSpeed(int s) { speed = s; }

std::string Enemy::getType() const{ return "Enemy"; }

Enemy::Enemy() : range(5), damage(10), speed(3){
    count++;
    setHealth(50);
}

Enemy::Enemy(int hp) : range(5), damage(10), speed(3){
    count++;
    setHealth(hp);
}

void Enemy::attack(Player& player, int dmg) {
    player.damage(dmg);
}

bool Enemy::collides(const sf::Vector2f& testPos, const Map& map) const {
    const float radius = 0.3f;

    // Check 5 points: 4 corners of bounding box + center
    std::vector<sf::Vector2f> points = {
        {testPos.x - radius, testPos.y - radius},  // Bottom-left
        {testPos.x + radius, testPos.y - radius},  // Bottom-right
        {testPos.x - radius, testPos.y + radius},  // Top-left
        {testPos.x + radius, testPos.y + radius},  // Top-right
        testPos  // Center
    };

    for (const auto& p : points) {
        int mx = static_cast<int>(p.x);
        int my = static_cast<int>(p.y);
        if (mx < 0 || mx >= map.getMapWidth() || my < 0 || my >= map.getMapHeight() ||
            map.getGrid()[my][mx] != 0) {
            return true;  // Hits wall or out of bounds
        }
    }
    return false;  // Safe
}