#include "TitleScene.h"

using namespace KamataEngine;

TitleScene::~TitleScene() {

	delete sprite_;

}

void TitleScene::Initialize() {

	input_ = Input::GetInstance();

	isFinished_ = false;
	textureHandle_ = TextureManager::Load("uvChecker.png");
	sprite_ = Sprite::Create(textureHandle_, {0, 0});

}

void TitleScene::Update() {

	if (input_->TriggerKey(DIK_SPACE)) {
	
	isFinished_ = true;
	
	}

}

void TitleScene::Draw() {

	KamataEngine::DirectXCommon* dxCommon_ = KamataEngine::DirectXCommon::GetInstance();
	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

	Sprite::PreDraw(commandList);
	sprite_->Draw();
	Sprite::PostDraw();

}
