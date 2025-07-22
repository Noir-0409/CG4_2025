#include "TitleScene.h"

using namespace KamataEngine;

TitleScene::TitleScene() {}

TitleScene::~TitleScene() {}

void TitleScene::Initialize() {

textureHandle_ = TextureManager::Load("uvChecker.png");

titleSprite_ = Sprite::Create(textureHandle_, {100, 50});

}

void TitleScene::Update() {}

void TitleScene::Draw() {

	titleSprite_->Draw();

}
