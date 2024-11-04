#ifndef PLUGGUNTURRET6_HPP
#define PLUGGUNTURRET6_HPP
#include "Turret.hpp"

class PlugGunTurret6 : public Turret {
public:
    static const int Price;
    PlugGunTurret6(float x, float y);
    void CreateBullet() override;
};
#endif // PLUGGUNTURRET_HPP
#pragma once
#pragma once
