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


};