#include <allegro5/base.h>
#include <cmath>
#include <string>
#include "AudioHelper.hpp"
#include "WoodBullet.hpp"
#include "Group.hpp"
#include "PlugGunTurret6.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "ExplosionEffect2.hpp"

const int PlugGunTurret6::Price = 5;
PlugGunTurret6::PlugGunTurret6(float x, float y) :
    // TODO 3 (1/5): You can imitate the 2 files: 'PlugGunTurret.hpp', 'PlugGunTurret.cpp' to create a new turret.
    Turret("play/tower-base.png", "play/turret-7.png", x, y, 200, Price, 1.5) {
    // Move center downward, since we the turret head is slightly biased upward
    Anchor.y += 8.0f / GetBitmapHeight();
}
void PlugGunTurret6::CreateBullet() {
    return;
}
