#pragma once
#include <KamataEngine.h>
#include "Model2.h"

using namespace KamataEngine;

// パーティクル
class Particle {

public:
	void Initialize(Model2* model);

	void Update();

	void Draw(Camera& camera);

private:
	// ワールド変換データ
	WorldTransform worldTransform_;

	// モデル
	Model2* model_ = nullptr;

};