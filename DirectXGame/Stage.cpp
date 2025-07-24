#include "Stage.h"

using namespace KamataEngine;

Stage::~Stage() {

	delete sprite1_;
	delete sprite2_;

}

void Stage::Initialize() {

pos1_ = {0.0f, 0.0f};
pos2_ = {2160.0f, 0.0f};

textureHandle_ = TextureManager::Load("stageBG.png");
sprite1_ = Sprite::Create(textureHandle_, pos1_);
sprite2_ = Sprite::Create(textureHandle_, pos2_);

scrollSpeed_ = 2.0f;

}

void Stage::Update() {

  pos1_.x -= scrollSpeed_;
	pos2_.x -= scrollSpeed_;

	if (pos1_.x <= -2160.0f) {
		pos1_.x = pos2_.x + 2160.0f;
	}
	if (pos2_.x <= -2160.0f) {
		pos2_.x = pos1_.x + 2160.0f;
	}

	sprite1_->SetPosition(pos1_);
	sprite2_->SetPosition(pos2_);

}

void Stage::Draw() {

	sprite1_->Draw();
	sprite2_->Draw();

}
