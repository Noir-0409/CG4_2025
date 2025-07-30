#include "TitleScene.h"

using namespace KamataEngine;

TitleScene::~TitleScene() {

	delete sprite_;
	delete spriteBG_;

}

void TitleScene::Initialize() {

	input_ = Input::GetInstance();

	isFinished_ = false;

	spritePos_ = {0, -300};
	
	textureHandle_ = TextureManager::Load("title.png");
	textureHandleBG_ = TextureManager::Load("titleBG.png");
	sprite_ = Sprite::Create(textureHandle_, spritePos_);
	spriteBG_ = Sprite::Create(textureHandleBG_, {0, 0});

}

void TitleScene::Update() {

	if (input_->TriggerKey(DIK_SPACE)) {
		isFinished_ = true;
	}

	const float kTargetY = 200.0f;
	const float kMoveSpeed = 2.0f;

	if (spritePos_.y < kTargetY) {
		spritePos_.y += kMoveSpeed;
		if (spritePos_.y > kTargetY) {
			spritePos_.y = kTargetY;
		}
		sprite_->SetPosition(spritePos_);
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
