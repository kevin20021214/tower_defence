#ifndef boss_HPP
#define boss_HPP
#include "Enemy.hpp"
#include "Point.hpp"
#include "Sprite.hpp"
class boss : public Enemy {
public:
    boss(int x, int y);
    void Update(float deltaTime) override;
    float re = 5;
};
#endif // REDNORMALENEMY_HPP
#pragma once
