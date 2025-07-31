#include "Number.h"

//void Number::Initialize() {
//
//	 uint32_t textureHandle = TextureManager::Load("number.png");
//
//	for (int i = 0; i < 5; i++) {
//		
//		sprite_[i] = Sprite::Create(textureHandle, {100.0f + size.x * i, 5});
//		sprite_[i]->SetSize(size);
//
//	}
//
//}

#include "Number.h"

void Number::Initialize() {

	uint32_t textureHandle = TextureManager::Load("number.png");

	
	float spacing = size.x * 0.7f;

	for (int i = 0; i < 5; i++) {
		Vector2 pos = {100.0f + spacing * i, 50.0f};
		sprite_[i] = Sprite::Create(textureHandle, pos);
		sprite_[i]->SetSize(size);

		sprite_[i]->SetTextureRect({0.0f, 0.0f}, size);
	}
}

void Number::Update() {}

void Number::Draw() {

	for (int i = 0; i < 5; i++) {
		if (sprite_[i]) {
			sprite_[i]->Draw();
		}
	}

}
