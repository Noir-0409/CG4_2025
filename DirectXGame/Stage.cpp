#include "Stage.h"

using namespace KamataEngine;

Stage::~Stage() {}

void Stage::Initialize() {

textureHandle_ = TextureManager::Load("stageBG.png");
sprite1_ = Sprite::Create(textureHandle_, {0, 0});
sprite2_ = Sprite::Create(textureHandle_, {2160, 0});

}

void Stage::Update() {}

void Stage::Draw() {

	sprite1_->Draw();
	sprite2_->Draw();

}
