#include "Graph.h"

using namespace KamataEngine;

Graph::~Graph() {}

void Graph::Initialize() {

	uint32_t textureHandle = TextureManager::Load("white1x1.png");

	greenSprite_ = Sprite::Create(textureHandle, position_);
	greenSprite_->SetSize({totalWidth_, height_});
	greenSprite_->SetColor({0, 255, 0, 0.8f});

	redSprite_ = Sprite::Create(textureHandle, position_);
	redSprite_->SetSize({0.0f, height_});
	redSprite_->SetColor({255, 0, 0, 0.8f});
}

void Graph::Update() {

	elapsedTime_ += 1.0f / 60.0f;
	if (elapsedTime_ > duration_)
		elapsedTime_ = duration_;

	float progress = elapsedTime_ / duration_;
	float redWidth = totalWidth_ * progress;

	redSprite_->SetSize({redWidth, height_});

	float redPosX = position_.x + totalWidth_ - redWidth;
	redSprite_->SetPosition({redPosX, position_.y});
}

void Graph::Draw() {

	if (greenSprite_)
		greenSprite_->Draw();
	if (redSprite_)
		redSprite_->Draw();
}
