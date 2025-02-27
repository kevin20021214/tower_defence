#include <allegro5/base.h>
#include <random>
#include <string>
#include "DirtyEffect.hpp"
#include "Enemy.hpp"
#include "WoodBullet3.hpp"
#include "Group.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Bullet.hpp"
#include "Collider.hpp"
#include "Enemy.hpp"
#include "GameEngine.hpp"
#include "Group.hpp"
#include "IObject.hpp"
#include "IScene.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Sprite.hpp"
#include "Turret.hpp"
#include <iostream>
class Turret;

WoodBullet3::WoodBullet3(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent) :
    Bullet("play/bullet-7.png", 400, 4, position, forwardDirection, rotation - ALLEGRO_PI / 2, parent) {
    // TODO 3 (2/5): You can imitate the 2 files: 'WoodBullet.hpp', 'WoodBullet.cpp' to create a new bullet.
}
void WoodBullet3::OnExplode(Enemy* enemy) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(2, 5);
    getPlayScene()->GroundEffectGroup->AddNewObject(new DirtyEffect("play/dirty-1.png", dist(rng), enemy->Position.x, enemy->Position.y));
}
void WoodBullet3::Update(float deltaTime) {
	if (parent->t == 1&&wt==0) {
		wt = 1;
		Velocity = Velocity * 2;
	}
	else if (parent->t == 0&&wt==1) {
		wt = 0;
		Velocity = Velocity / 2;
	}
	Engine::Point ac = (parent->Position-Position).Normalize()*Velocity.MagnitudeSquared() / (parent->CollisionRadius);
	Velocity = Velocity + ac*deltaTime;
	Sprite::Update(deltaTime);
	PlayScene* scene = getPlayScene();
	// Can be improved by Spatial Hash, Quad Tree, ...
	// However simply loop through all enemies is enough for this program.
	for (auto& it : scene->EnemyGroup->GetObjects()) {
		Enemy* enemy = dynamic_cast<Enemy*>(it);
		if (!enemy->Visible)
			continue;
		if (Engine::Collider::IsCircleOverlap(Position, CollisionRadius, enemy->Position, enemy->CollisionRadius)) {
			OnExplode(enemy);
			enemy->Hit(damage);
			parent->numbul--;
			getPlayScene()->BulletGroup->RemoveObject(objectIterator);
			return;
		}
	}
	// Check if out of boundary.
	if (!Engine::Collider::IsRectOverlap(Position - Size / 2, Position + Size / 2, Engine::Point(0, 0), PlayScene::GetClientSize())) {
		parent->numbul--;
		getPlayScene()->BulletGroup->RemoveObject(objectIterator);
	}

}
