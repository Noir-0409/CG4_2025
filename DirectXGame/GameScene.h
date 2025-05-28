#pragma once
#include "Effect.h"
#include "KamataEngine.h"

using namespace KamataEngine;

// ゲームシーン
class GameScene {

public:
	GameScene();

	~GameScene();

	// 初期化
	void Initialize();

	// 更新
	void Update();

	// 描画
	void Draw();

	void EffectBorn(Vector3 position);

private:
	// モデル
	Model* modelEffect_ = nullptr;

	// カメラ
	Camera camera_;

	// エフェクト
	std::list<Effect*> effects_;



};