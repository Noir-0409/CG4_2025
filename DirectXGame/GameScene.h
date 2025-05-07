#pragma once
#include "3d/Model.h"
#include "KamataEngine.h"
#include "Particle.h"

using namespace KamataEngine;

// ゲームシーン
class GameScene {

public:
	~GameScene();

	// 初期化
	void Initialize();

	// 更新
	void Update();

	// 描画
	void Draw();

private:
	// モデルデータ
	Model* modelParticle_ = nullptr;

	// カメラ
	Camera camera_;

	// パーティクル
	Particle* particle_ = nullptr;
};