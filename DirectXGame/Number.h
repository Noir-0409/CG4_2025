#pragma once
#include "KamataEngine.h"
#include <chrono>

using namespace KamataEngine;

class Number {

public:
	void Initialize();

	void Update();

	void Draw();

	void SetNumber(int number);

private:
	Sprite* sprite_[5] = {};

	Vector2 size = {32.0f, 64.0f};

	 std::chrono::steady_clock::time_point prevTime_;

	int currentNumber = 0;
	float elapsedTime = 0.0f;

};