#pragma once
#include "KamataEngine.h"

using namespace KamataEngine;

class Number {

public:
	void Initilaize();

	void Update();

	void Draw();

private:
	Sprite* sprite_[5] = {};
};