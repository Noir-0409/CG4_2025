#include "GameScene.h"

GameScene::~GameScene() {

	Model2::StaticFinalize();
	delete modelParticle_;
	delete particle_;
}

void GameScene::Initialize() {

	// モデルデータ生成
	modelParticle_ = Model2::CreateSquare(5);

	// カメラの初期化
	camera_.Initialize();

	Model2::StaticInitialize();

	// パーティクルの生成
	particle_ = new Particle();

	// パーティクルの初期化
	particle_->Initialize(modelParticle_);
}

void GameScene::Update() { particle_->Update(); }

void GameScene::Draw() {

	// DirectXCommonインスタンスの所得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	// 3Dモデル描画前処理
	Model2::PreDraw(dxCommon->GetCommandList());

	particle_->Draw(camera_);

	// 3Dモデル描画後処理
	Model2::PostDraw();
}
