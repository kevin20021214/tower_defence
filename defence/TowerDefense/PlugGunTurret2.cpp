#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "WoodBullet2.hpp"
#include "Group.hpp"
#include "PlugGunTurret2.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "ExplosionEffect2.hpp"
const int PlugGunTurret2::Price = 50;
PlugGunTurret2::PlugGunTurret2(float x, float y) :
    // TODO 3 (1/5): You can imitate the 2 files: 'PlugGunTurret.hpp', 'PlugGunTurret.cpp' to create a new turret.
    Turret("play/tower-base.png", "play/turret-1.png", x, y, 300, Price, 1.5) {
    // Move center downward, since we the turret head is slightly biased upward
    Anchor.y += 8.0f / GetBitmapHeight();
}
void PlugGunTurret2::CreateBullet() {
    Engine::Point diff = Engine::Point(cos(Rotation - ALLEGRO_PI / 2), sin(Rotation - ALLEGRO_PI / 2));
    float rotation = atan2(diff.y, diff.x);
    Engine::Point normalized = diff.Normalize();
    // Change bullet position to the front of the gun barrel.
    getPlayScene()->BulletGroup->AddNewObject(new WoodBullet2(Position + normalized * 40, diff, rotation, this));
    // TODO 4 (2/2): Add a ShootEffect here. Remember you need to include the class.
    getPlayScene()->EffectGroup->AddNewObject(new ExplosionEffect2(Position.x + diff.x * 50, Position.y + diff.y * 50));
    AudioHelper::PlayAudio("gun.wav");
}
