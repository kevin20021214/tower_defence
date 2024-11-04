#ifndef PLUGGUNTURRET4_HPP
#define PLUGGUNTURRET4_HPP
#include "Turret.hpp"

class PlugGunTurret4 : public Turret {
public:
    static const int Price;
    PlugGunTurret4(float x, float y);
    void CreateBullet() override;
    void Update(float deltaTime) override;
};
#endif // PLUGGUNTURRET_HPP
#pragma once
