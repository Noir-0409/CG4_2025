#pragma once
#include "KamataEngine.h"

using namespace KamataEngine;

class Stage {

public:

~Stage();

void Initialize();

void Update();

void Draw();

private:

uint32_t textureHandle_ = 0;
Sprite* sprite1_ = nullptr;
Sprite* sprite2_ = nullptr;

float scrollSpeed_ = 0.0f;

Vector2 pos1_ = {0.0f, 0.0f};
Vector2 pos2_ = {0.0f, 0.0f};

};