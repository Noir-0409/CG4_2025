#pragma once
#include "KamataEngine.h"

using namespace KamataEngine;

class Graph {

public:

~Graph();

void Initialize();

void Update();

void Draw();

private:

Sprite* greenSprite_ = nullptr;
Sprite* redSprite_ = nullptr;

float elapsedTime_ = 0.0f;
float duration_ = 5.0f;

float totalWidth_ = 250.0f;
float height_ = 50.0f;
Vector2 position_ = {100.0f, 100.0f};

};