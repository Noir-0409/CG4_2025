#include "Number.h"

void Number::Initilaize() {

	uint32_t textureHandle = TextureManager::Load("number.png");

	for (int i = 0; i < 5; i++) {
	
		sprite_[i] = Sprite::Create(textureHandle, {100.0f, +size.x * i, 5});
		sprite_[i]->SetSize();
	
	}

}

void Number::Update() {}

void Number::Draw() {}
