#pragma once
#pragma once
#ifndef WOODBULLET3_HPP
#define WOODBULLET3_HPP
#include "Bullet.hpp"
#include "Sprite.hpp"
class Enemy;
class Turret;
namespace Engine {
    struct Point;
}  // namespace Engine
class WoodBullet3 : public Bullet {
public:
    explicit WoodBullet3(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent);
    void OnExplode(Enemy* enemy) override;
    void Update(float deltaTime) override;
    bool wt=0;
};
#endif // WOODBULLET_HPP
