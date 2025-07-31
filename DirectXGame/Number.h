#pragma once
#include "KamataEngine.h"

using namespace KamataEngine;

class Number {

public:
	void Initialize();

	void Update();

	void Draw();

private:
	Sprite* sprite_[5] = {};

	Vector2 size = {32.0f, 64.0f};

};