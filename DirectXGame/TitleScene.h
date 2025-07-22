#pragma once
#include <cstdint>
#include <KamataEngine.h>

class TitleScene {

public:

TitleScene();

~TitleScene();

void Initialize();

void Update();

void Draw();

private:

uint32_t textureHandle_ = 0u;

KamataEngine::Sprite* titleSprite_ = nullptr;

};