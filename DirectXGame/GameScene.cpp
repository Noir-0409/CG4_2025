#include "GameScene.h"

GameScene::~GameScene() {

	delete modelParticle_;
	delete particle_;
	delete stage_;

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

	input_ = Input::GetInstance();
}

void GameScene::Update() {
	particle_->Update();

	if (input_->TriggerKey(DIK_SPACE)) {

		isFinished_ = true;
	}

	stage_->Update();
}

void GameScene::Draw() {

	//// DirectXCommonインスタンスの所得
	//DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	//// 3Dモデル描画前処理
	//Model::PreDraw(dxCommon->GetCommandList());

	//
	//player_->Draw(camera_);

	//// 3Dモデル描画後処理
	//Model::PostDraw();

	//// コマンドリストの取得
	//ID3D12GraphicsCommandList* commandList = dxCommon->GetCommandList();

	//Sprite::PreDraw(commandList);

	//stage_->Draw();

	//Sprite::PostDraw();

	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Sprite::PreDraw(dxCommon->GetCommandList());

	stage_->Draw();

	Sprite::PostDraw();

	dxCommon->ClearDepthBuffer();

	Model::PreDraw(dxCommon->GetCommandList());

	player_->Draw(camera_);

	Model::PostDraw();

	Sprite::PreDraw(dxCommon->GetCommandList());

	Sprite::PostDraw();

}
