#include "GameScene.h"

GameScene::GameScene() {}

GameScene::~GameScene() {

	delete modelEffect_;
	delete effect_;
}

void GameScene::Initialize() {

	modelEffect_ = Model::CreateSphere(2, 2);

	camera_.Initialize();

	effect_ = new Effect();
	effect_->Initialize(modelEffect_);
}

void GameScene::Update() { effect_->Update(); }

void GameScene::Draw() {

	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Model::PreDraw(dxCommon->GetCommandList());

	effect_->Draw(camera_);

	Model::PostDraw();
}
