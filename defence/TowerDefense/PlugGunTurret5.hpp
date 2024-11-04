#ifndef PLUGGUNTURRET5_HPP
#define PLUGGUNTURRET5_HPP
#include "Turret.hpp"

class PlugGunTurret5 : public Turret {
public:
    static const int Price;
    PlugGunTurret5(float x, float y);
    void CreateBullet() override;
};
#endif // PLUGGUNTURRET_HPP
#pragma once
