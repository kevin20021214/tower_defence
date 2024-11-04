#ifndef PLUGGUNTURRET2_HPP
#define PLUGGUNTURRET2_HPP
#include "Turret.hpp"

class PlugGunTurret2 : public Turret {
public:
    static const int Price;
    PlugGunTurret2(float x, float y);
    void CreateBullet() override;
};
#endif // PLUGGUNTURRET_HPP
#pragma once
