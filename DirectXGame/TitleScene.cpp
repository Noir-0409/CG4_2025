#include "TitleScene.h"

using namespace KamataEngine;

TitleScene::~TitleScene() {

	delete sprite_;
	delete spriteBG_;

}

void TitleScene::Initialize() {

	input_ = Input::GetInstance();

	isFinished_ = false;
	textureHandle_ = TextureManager::Load("title.png");
	textureHandleBG_ = TextureManager::Load("titleBG.png");
	sprite_ = Sprite::Create(textureHandle_, {0, 0});
	spriteBG_ = Sprite::Create(textureHandleBG_, {0, 0});

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
	spriteBG_->Draw();
	sprite_->Draw();
	Sprite::PostDraw();

}
