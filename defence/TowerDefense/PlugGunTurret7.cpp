#include <allegro5/base.h>
#include <cmath>
#include <string>
#include <iostream>
#include "AudioHelper.hpp"
#include "WoodBullet3.hpp"
#include "Group.hpp"
#include "PlugGunTurret7.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "ExplosionEffect2.hpp"
const int PlugGunTurret7::Price = 10;
PlugGunTurret7::PlugGunTurret7(float x, float y) :
    // TODO 3 (1/5): You can imitate the 2 files: 'PlugGunTurret.hpp', 'PlugGunTurret.cpp' to create a new turret.
    Turret("play/tower-base.png", "play/turret-4.png", x, y, 300, Price, 1.0) {
    // Move center downward, since we the turret head is slightly biased upward
    Anchor.y += 8.0f / GetBitmapHeight();
}
void PlugGunTurret7::CreateBullet() {
}
void PlugGunTurret7::Update(float deltaTime) {
    Sprite::Update(deltaTime);
    imgBase.Position = Position;
    imgBase.Tint = Tint;
}