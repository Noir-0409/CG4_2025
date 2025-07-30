#include "GameScene.h"

GameScene::~GameScene() {

	delete modelParticle_;
	delete particle_;
	delete stage_;
	delete modelPlayer_;
	delete player_;
	delete graph_;

}

void GameScene::Initialize() {

	// モデルデータ生成
	modelParticle_ = Model::CreateSphere(4, 4);

	modelPlayer_ = Model::CreateFromOBJ("Player");

	// カメラの初期化
	camera_.Initialize();

	// パーティクルの生成
	particle_ = new Particle();

	// パーティクルの初期化
	particle_->Initialize(modelParticle_);

	player_ = new Player();

	player_->Initialize(modelPlayer_);

	stage_ = new Stage();

	stage_->Initialize();

	graph_ = new Graph();

	graph_->Initialize();

	input_ = Input::GetInstance();
}

void GameScene::Update() {
	particle_->Update();

	if (input_->TriggerKey(DIK_SPACE)) {

		isFinished_ = true;
	}

	player_->Update();

	stage_->Update();

	graph_->Update();

}

void GameScene::Draw() {

	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Sprite::PreDraw(dxCommon->GetCommandList());

	stage_->Draw();

	Sprite::PostDraw();

	dxCommon->ClearDepthBuffer();

	Model::PreDraw(dxCommon->GetCommandList());

	player_->Draw(camera_);

	Model::PostDraw();

	Sprite::PreDraw(dxCommon->GetCommandList());

	graph_->Draw();

	Sprite::PostDraw();

}
