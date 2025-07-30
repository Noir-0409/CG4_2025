#include "TitleScene.h"

using namespace KamataEngine;

TitleScene::~TitleScene() {

	delete sprite_;
	delete spriteBG_;
	delete spaceSprite_;
}

void TitleScene::Initialize() {

	input_ = Input::GetInstance();

	isFinished_ = false;

	spritePos_ = {0, -300};

	textureHandle_ = TextureManager::Load("title.png");
	textureHandleBG_ = TextureManager::Load("titleBG.png");
	spaceTextureHandle_ = TextureManager::Load("space.png");
	sprite_ = Sprite::Create(textureHandle_, spritePos_);
	spriteBG_ = Sprite::Create(textureHandleBG_, {0, 0});
	spaceSprite_ = Sprite::Create(spaceTextureHandle_, {540, 600});
}

void TitleScene::Update() {

	if (input_->TriggerKey(DIK_SPACE)) {
		isFinished_ = true;
	}

	const float kTargetY = 80.0f;
	const float kMoveSpeed = 2.0f;

	if (spritePos_.y < kTargetY) {
		spritePos_.y += kMoveSpeed;
		if (spritePos_.y > kTargetY) {
			spritePos_.y = kTargetY;
		}
		sprite_->SetPosition(spritePos_);
	}

	const float kBlinkCycle = 0.5f;
	timer_ += 1.0f / 60.0f;

	if (timer_ >= kBlinkCycle) {
		timer_ = 0.0f;
		isBlinkVisible_ = !isBlinkVisible_;
	}
}

void TitleScene::Draw() {

	KamataEngine::DirectXCommon* dxCommon_ = KamataEngine::DirectXCommon::GetInstance();
	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

	Sprite::PreDraw(commandList);

	spriteBG_->Draw();
	sprite_->Draw();

	if (isBlinkVisible_) {
		spaceSprite_->Draw();
	}

	Sprite::PostDraw();
}
