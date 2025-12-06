#include "Headers/Player.h"
#include <cmath>
#include "Headers/Constants.h"
#include "Headers/Map.h"
#include <vector>
#include <cmath>

Player::Player() : speed(MOVE_SPEED), dir(-1.0f, 0.0f), plane(0.0f, 0.66f) {
    setPosition(sf::Vector2f(22.0f, 12.0f));  // Starting pos
}

void Player::setSpeed(int newSpeed) { speed = newSpeed; }

float Player::getSpeed() const { return speed; }

void Player::damage(int dmg) {
    setHealth(getHealth() - dmg);
}

void Player::move(float deltaTime, const Map& map, const sf::Keyboard::Key forward, const sf::Keyboard::Key backward) {
    float moveSpeed = getSpeed() * deltaTime;
    sf::Vector2f pos = getPosition();
    sf::Vector2f playerDir = ::getDir(*this);
    
    if (sf::Keyboard::isKeyPressed(forward)) {
        sf::Vector2f moveDelta = playerDir * moveSpeed;

        // Separate X and Y for wall sliding (prevents clipping)
        sf::Vector2f newPosX = pos;
        newPosX.x += moveDelta.x;
        if (!collides(newPosX, map)) {
            pos.x = newPosX.x;
        }

        sf::Vector2f newPosY = pos;
        newPosY.y += moveDelta.y;
        if (!collides(newPosY, map)) {
            pos.y = newPosY.y;
        }
    }

    if (sf::Keyboard::isKeyPressed(backward)) {
        sf::Vector2f moveDelta = playerDir * (-moveSpeed);

        // Separate X and Y for wall sliding (to avoid clipping)
        sf::Vector2f newPosX = pos;
        newPosX.x += moveDelta.x;
        if (!collides(newPosX, map)) {
            pos.x = newPosX.x;
        }

        sf::Vector2f newPosY = pos;
        newPosY.y += moveDelta.y;
        if (!collides(newPosY, map)) {
            pos.y = newPosY.y;
        }
    }
    
    setPosition(pos);
}

void Player::rotate(float deltaTime, const sf::Keyboard::Key left, const sf::Keyboard::Key right) {
    float rotSpeed = ROT_SPEED * deltaTime;

    if (sf::Keyboard::isKeyPressed(right)) rotSpeed = -rotSpeed;  // Invert for right turn
    if (sf::Keyboard::isKeyPressed(left) || sf::Keyboard::isKeyPressed(right)) {
        sf::Vector2f playerDir = ::getDir(*this);
        sf::Vector2f playerPlane = ::getPlane(*this);
        
        float oldDirX = playerDir.x;
        playerDir.x = playerDir.x * cos(rotSpeed) - playerDir.y * sin(rotSpeed);
        playerDir.y = oldDirX * sin(rotSpeed) + playerDir.y * cos(rotSpeed);

        float oldPlaneX = playerPlane.x;
        playerPlane.x = playerPlane.x * cos(rotSpeed) - playerPlane.y * sin(rotSpeed);
        playerPlane.y = oldPlaneX * sin(rotSpeed) + playerPlane.y * cos(rotSpeed);
        
        ::setDir(*this, playerDir);
        ::setPlane(*this, playerPlane);
    }
}

bool Player::collides(const sf::Vector2f& testPos, const Map& map) const {
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