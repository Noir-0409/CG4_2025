#pragma once
#include "KamataEngine.h"

using namespace KamataEngine;

class TitleScene {

public:

	~TitleScene();

	void Initialize();

	void Update();

	void Draw();

	bool IsFinished() const { return isFinished_; }

private:
	
	Input* input_ = nullptr;

	uint32_t textureHandle_ = 0;
	Sprite* sprite_ = nullptr;

	bool isFinished_ = false;

};