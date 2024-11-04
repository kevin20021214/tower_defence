#include <allegro5/base.h>
#include <cmath>
#include <string>
#include <iostream>
#include "AudioHelper.hpp"
#include "WoodBullet3.hpp"
#include "Group.hpp"
#include "PlugGunTurret4.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "ExplosionEffect2.hpp"
#include"PlugGunTurret7.hpp"
#include"Collider.hpp"
const int PlugGunTurret4::Price = 30;
PlugGunTurret4::PlugGunTurret4(float x, float y) :
    //imitate the 2 files: 'PlugGunTurret.hpp', 'PlugGunTurret.cpp' to create a new turret.
    Turret("play/tower-base.png", "play/turret-3.png", x, y, 200, Price, 1.0) {
    // Move center downward, since we the turret head is slightly biased upward
    Anchor.y += 8.0f / GetBitmapHeight();
}
void PlugGunTurret4::CreateBullet() {
    // Change bullet position to the front of the gun barrel.Create four bullet.
    getPlayScene()->BulletGroup->AddNewObject(new WoodBullet3(Position + Engine::Point(CollisionRadius,0),Engine::Point(0,1),0, this));
    getPlayScene()->BulletGroup->AddNewObject(new WoodBullet3(Position + Engine::Point(0, CollisionRadius), Engine::Point(-1,0 ), 0, this));
    getPlayScene()->BulletGroup->AddNewObject(new WoodBullet3(Position + Engine::Point(-CollisionRadius, 0), Engine::Point(0, -1), 0, this));
    getPlayScene()->BulletGroup->AddNewObject(new WoodBullet3(Position + Engine::Point(0,-CollisionRadius), Engine::Point(1, 0), 0, this));
    numbul = 4;
    AudioHelper::PlayAudio("gun.wav");
}
void PlugGunTurret4::Update(float deltaTime) {
    Sprite::Update(deltaTime);
	//accelerate the bullet.
	if (t == 0) {
		for (auto it : getPlayScene()->TowerGroup->GetObjects()) {
			if (dynamic_cast<PlugGunTurret7*>(it)) {
				auto i = dynamic_cast<Turret*>(it);
				if (Engine::Collider::IsCircleOverlap(i->Position, i->CollisionRadius, Position, 0)) {
					t = 1;
					break;
				}
			}
		}
	}
	else if (t == 1) {
		bool tr = 0;
		for (auto it : getPlayScene()->TowerGroup->GetObjects()) {
			if (dynamic_cast<PlugGunTurret7*>(it)) {
				auto i = dynamic_cast<Turret*>(it);
				if (Engine::Collider::IsCircleOverlap(i->Position, i->CollisionRadius, Position, 0)) {
					tr = 1;
					break;
				}
			}
		}
		if (tr == 0) {
			t = 0;
		}
	}
    imgBase.Position = Position;
    imgBase.Tint = Tint;
    if (Enabled) {
        if (numbul == 0) {
            CreateBullet();
        }
    }
}
