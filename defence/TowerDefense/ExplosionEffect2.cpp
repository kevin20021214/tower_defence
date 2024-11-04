#include <cmath>
#include <string>

#include "ExplosionEffect2.hpp"
#include "GameEngine.hpp"
#include "Group.hpp"
#include "IScene.hpp"
#include "PlayScene.hpp"
#include "Resources.hpp"

// TODO 4 (1/2): You can imitate the 2 files: 'ExplosionEffect.hpp', 'ExplosionEffect.cpp' to create shoot effect.
PlayScene* ExplosionEffect2::getPlayScene() {
	return dynamic_cast<PlayScene*>(Engine::GameEngine::GetInstance().GetActiveScene());
}
ExplosionEffect2::ExplosionEffect2(float x, float y) : Sprite("play/shoot-1.png", x, y), timeTicks(0) {
	for (int i = 1; i <= 4; i++) {
		bmps.push_back(Engine::Resources::GetInstance().GetBitmap("play/shoot-" + std::to_string(i) + ".png"));
	}
}
void ExplosionEffect2::Update(float deltaTime) {
	timeTicks += deltaTime;
	if (timeTicks >= timeSpan) {
		getPlayScene()->EffectGroup->RemoveObject(objectIterator);
		return;
	}
	int phase = floor(timeTicks / timeSpan * bmps.size());
	bmp = bmps[phase];
	Sprite::Update(deltaTime);
}
