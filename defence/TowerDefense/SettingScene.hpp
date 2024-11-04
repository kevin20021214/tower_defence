#ifndef SETTINGSCENE_HPP
#define SETTINGSCENE_HPP
#include <allegro5/allegro_audio.h>
#include <functional>
#include <memory>
#include <string>
#include "AudioHelper.hpp"
#include "GameEngine.hpp"
#include "ImageButton.hpp"
#include "Label.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Resources.hpp"
#include "Slider.hpp"
#include "StageSelectScene.hpp"
#include "IScene.hpp"
class SettingScene final : public Engine::IScene {
private:
	std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE> bgmInstance;
	float ticks;
	ALLEGRO_SAMPLE_ID bgmId;
public:
	explicit SettingScene() = default;
	void Initialize() override;
	void BGMSlideOnValueChanged(float);
	void SFXSlideOnValueChanged(float);
	void Terminate() override;
	void PlayOnClick(int stage);
};

#endif // SETTINGSCENE_HPP