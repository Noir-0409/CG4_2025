#include "GameScene.h"
#include <random>

GameScene::GameScene() {}

GameScene::~GameScene() {

	delete modelEffect_;
	for (Effect* effects : effects_) {

		delete effects;
	}
}

void GameScene::Initialize() {

	modelEffect_ = Model::CreateSphere(2, 2);

	camera_.Initialize();

	for (int i = 0; i < 10; i++) {
	
	Effect* effects = new Effect();
	effects->Initialize(modelEffect_);
	effects_.push_back(effects);

	}

}

void GameScene::Update() {
	for (Effect* effects : effects_) {

		effects->Update();

	}
}

void GameScene::Draw() {

	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Model::PreDraw(dxCommon->GetCommandList());

	for (Effect* effects : effects_) {

		effects->Draw(camera_);
	}

	Model::PostDraw();
}
