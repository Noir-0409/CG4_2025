#pragma once
#include "3d/Model.h"
#include "KamataEngine.h"
#include "Particle.h"
#include "Stage.h"
#include "Player.h"
#include "Graph.h"

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

	bool IsFinished() const { return isFinished_; }

private:
	// モデルデータ
	Model* modelParticle_ = nullptr;

	// カメラ
	Camera camera_;

	// パーティクル
	Particle* particle_ = nullptr;

	Stage* stage_ = nullptr;

	Input* input_ = nullptr;
	bool isFinished_ = false;

	Model* modelPlayer_ = nullptr;

	Player* player_ = nullptr;

	Graph* graph_ = nullptr;

};