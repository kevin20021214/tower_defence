#include <string>
#include <allegro5/allegro_primitives.h>
#include <allegro5/color.h>
#include <cmath>
#include <random>
#include <string>
#include <vector>
#include "notnomoalenemy2.hpp"
#include "AudioHelper.hpp"
#include "Bullet.hpp"
#include "DirtyEffect.hpp"
#include "Enemy.hpp"
#include "ExplosionEffect.hpp"
#include "GameEngine.hpp"
#include "Group.hpp"
#include "IScene.hpp"
#include "LOG.hpp"
#include "PlayScene.hpp"
#include "Turret.hpp"
#include "notnomalenemy.hpp"
NotNormalEnemy2::NotNormalEnemy2(int x, int y) : Enemy("play/dice-2.png", x, y, 25, 65, 9, 10) {
    // TODO 2 (1/3): You can imitate the 2 files: 'RedNormalEnemy.hpp', 'RedNormalEnemy.cpp' to create a new enemy.
}

void NotNormalEnemy2::OnExplode()
{
	Enemy* enemy;
	getPlayScene()->EffectGroup->AddNewObject(new ExplosionEffect(Position.x, Position.y));
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> distId(1, 3);
	std::uniform_int_distribution<std::mt19937::result_type> dist(1, 20);
	getPlayScene()->EnemyGroup->AddNewObject(enemy = new NotNormalEnemy(Position.x, Position.y));
	for (int i = 0; i < 10; i++) {
		// Random add 10 dirty effects.
		getPlayScene()->GroundEffectGroup->AddNewObject(new DirtyEffect("play/dirty-" + std::to_string(distId(rng)) + ".png", dist(rng), Position.x, Position.y));
	}
	enemy->UpdatePath(getPlayScene()->mapDistance);
}
