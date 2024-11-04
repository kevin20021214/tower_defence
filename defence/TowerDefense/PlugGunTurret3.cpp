#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "WoodBullet2.hpp"
#include "Group.hpp"
#include "PlugGunTurret3.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "ExplosionEffect2.hpp"
const int PlugGunTurret3::Price = 0;
PlugGunTurret3::PlugGunTurret3(float x, float y) :
    // TODO 3 (1/5): You can imitate the 2 files: 'PlugGunTurret.hpp', 'PlugGunTurret.cpp' to create a new turret.
    Turret("play/tower-base.png", "play/turret-2.png", x, y, 400, Price, 1.5) {
    // Move center downward, since we the turret head is slightly biased upward
    Anchor.y += 8.0f / GetBitmapHeight();
}
void PlugGunTurret3::CreateBullet() {
    Engine::Point diff = Engine::Point(cos(Rotation - ALLEGRO_PI / 2), sin(Rotation - ALLEGRO_PI / 2));
    float rotation = atan2(diff.y, diff.x);
    Engine::Point normalized = diff.Normalize();
    Engine::Point diff1 = Engine::Point(sin(Rotation - ALLEGRO_PI / 2),-cos(Rotation - ALLEGRO_PI / 2)).Normalize();
    // Change bullet position to the front of the gun barrel.
    getPlayScene()->BulletGroup->AddNewObject(new WoodBullet2(Position + normalized * 40+diff1*6, diff, rotation, this));
    getPlayScene()->BulletGroup->AddNewObject(new WoodBullet2(Position + normalized * 40-diff1*8, diff, rotation, this));
    // TODO 4 (2/2): Add a ShootEffect here. Remember you need to include the class.
    getPlayScene()->EffectGroup->AddNewObject(new ExplosionEffect2(Position.x + diff.x * 50, Position.y + diff.y * 50));
    AudioHelper::PlayAudio("gun.wav");
}
