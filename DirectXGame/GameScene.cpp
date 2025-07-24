#include "GameScene.h"

GameScene::~GameScene() {

	delete modelParticle_;
	delete particle_;
}

void GameScene::Initialize() {

	// モデルデータ生成
	modelParticle_ = Model::CreateSphere(4, 4);

	// カメラの初期化
	camera_.Initialize();

	// パーティクルの生成
	particle_ = new Particle();

	// パーティクルの初期化
	particle_->Initialize(modelParticle_);

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

	// DirectXCommonインスタンスの所得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	// 3Dモデル描画前処理
	Model::PreDraw(dxCommon->GetCommandList());

	// particle_->Draw(camera_);

	// 3Dモデル描画後処理
	Model::PostDraw();

	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon->GetCommandList();

	Sprite::PreDraw(commandList);

	stage_->Draw();

	Sprite::PostDraw();
}
