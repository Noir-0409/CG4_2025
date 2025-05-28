#pragma once

#include <KamataEngine.h>

using namespace KamataEngine;

// エフェクト
class Effect {

public:
	void Initialize(Model* model);

	void Update();

	void Draw(Camera& camera);

	bool IsFinished() { return isFinished_; }

private:
	// ワールド変換データ
	WorldTransform worldTransform_;

	// モデル
	Model* model_ = nullptr;
	
	bool isFinished_ = false;

	float counter_ = 0.0f;

	const float kDuration = 1.0f;

};