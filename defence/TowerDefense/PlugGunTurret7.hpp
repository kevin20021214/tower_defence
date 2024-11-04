#ifndef PLUGGUNTURRET7_HPP
#define PLUGGUNTURRET7_HPP
#include "Turret.hpp"

class PlugGunTurret7 : public Turret {
public:
    static const int Price;
    PlugGunTurret7(float x, float y);
    void CreateBullet() override;
    void Update(float) override;
};
#endif // PLUGGUNTURRET_HPP
#pragma once
#pragma once
