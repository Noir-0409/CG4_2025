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

	const float kBlinkCycle = 0.5f; // 秒（0.5秒ごとに切り替え）
	timer_ += 1.0f / 60.0f;    // 毎フレーム約1/60秒進める（仮に60FPS）

	if (timer_ >= kBlinkCycle) {
		timer_ = 0.0f;
		isBlinkVisible_ = !isBlinkVisible_; // ON/OFFを切り替える
	}

}

void TitleScene::Draw() {

	KamataEngine::DirectXCommon* dxCommon_ = KamataEngine::DirectXCommon::GetInstance();
	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

	Sprite::PreDraw(commandList);
	spriteBG_->Draw();
	//sprite_->Draw();
	if (isBlinkVisible_) {
		sprite_->Draw(); // 点滅するスプライト
	}
	Sprite::PostDraw();

}
