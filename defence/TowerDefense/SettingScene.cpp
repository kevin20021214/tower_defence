#include "Label.hpp"
#include "Point.hpp"
#include "Resources.hpp"
#include "SettingScene.hpp"
#include "StageSelectScene.hpp"
#include "AudioHelper.hpp"
#include "GameEngine.hpp"
#include "Image.hpp"
#include "ImageButton.hpp"
#include "Label.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "TurretButton.hpp"
void SettingScene::Initialize() {
    ticks = 0;
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    Engine::ImageButton* btn;
    Slider* sliderBGM, * sliderSFX;
    btn = new Engine::ImageButton("win/dirt.png", "win/floor.png", halfW+200, halfH * 7 / 4 - 50, 400, 100);
    btn->SetOnClickCallback(std::bind(&SettingScene::PlayOnClick, this, 3));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("Back", "pirulen.ttf", 48, halfW+400, halfH * 7 / 4, 0, 0, 0, 255, 0.5, 0.5));

    sliderBGM = new Slider(40 + halfW - 95, halfH - 50 - 2, 190, 4);
    sliderBGM->SetOnValueChangedCallback(std::bind(&SettingScene::BGMSlideOnValueChanged, this, std::placeholders::_1));
    AddNewControlObject(sliderBGM);
    AddNewObject(new Engine::Label("BGM: ", "pirulen.ttf", 28, 40 + halfW - 60 - 95, halfH - 50, 255, 255, 255, 255, 0.5, 0.5));
    sliderSFX = new Slider(40 + halfW - 95, halfH + 50 - 2, 190, 4);
    sliderSFX->SetOnValueChangedCallback(std::bind(&SettingScene::SFXSlideOnValueChanged, this, std::placeholders::_1));
    AddNewControlObject(sliderSFX);
    AddNewObject(new Engine::Label("SFX: ", "pirulen.ttf", 28, 40 + halfW - 60 - 95, halfH + 50, 255, 255, 255, 255, 0.5, 0.5));
    AddNewObject(new Engine::Label("Setting!", "pirulen.ttf", 48, halfW, halfH / 4 + 10, 255, 255, 255, 255, 0.5, 0.5));
    // Not safe if release resource while playing, however we only free while change scene, so it's fine.
    bgmInstance = AudioHelper::PlaySample("select.ogg", true, AudioHelper::BGMVolume);
    sliderBGM->SetValue(AudioHelper::BGMVolume);
    sliderSFX->SetValue(AudioHelper::SFXVolume);
}
void SettingScene::BGMSlideOnValueChanged(float value) {
    AudioHelper::ChangeSampleVolume(bgmInstance, value);
    AudioHelper::BGMVolume = value;
}
void SettingScene::SFXSlideOnValueChanged(float value) {
    AudioHelper::SFXVolume = value;
}
void SettingScene::Terminate() {
    AudioHelper::StopSample(bgmInstance);
    IScene::Terminate();
}
void SettingScene::PlayOnClick(int stage) {
    Engine::GameEngine::GetInstance().ChangeScene("stage-select");
}