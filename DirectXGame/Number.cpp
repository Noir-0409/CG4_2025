#include "Number.h"
#include <chrono>

void Number::Initialize() {

	uint32_t textureHandle = TextureManager::Load("number.png");

	float spacing = size.x * 0.7f;

	for (int i = 0; i < 5; i++) {
		Vector2 pos = {100.0f + spacing * i, 50.0f};
		sprite_[i] = Sprite::Create(textureHandle, pos);
		sprite_[i]->SetSize(size);
		sprite_[i]->SetTextureRect({0.0f, 0.0f}, size);
	}

	currentNumber = 0;
	SetNumber(currentNumber);

	prevTime_ = std::chrono::steady_clock::now();
	elapsedTime = 0.0f;
}

void Number::Update() {
	using namespace std::chrono;

	auto now = steady_clock::now();
	duration<float> delta = now - prevTime_;
	prevTime_ = now;

	elapsedTime += delta.count();

	if (elapsedTime >= 0.5f) {
		elapsedTime -= 0.5f;
		currentNumber++;
		if (currentNumber > 99999)
			currentNumber = 0;
		SetNumber(currentNumber);
	}
}

void Number::Draw() {
	for (int i = 0; i < 5; i++) {
		if (sprite_[i]) {
			sprite_[i]->Draw();
		}
	}
}

void Number::SetNumber(int number) {
	int divisor = 10000;
	for (int i = 0; i < 5; i++) {
		int digit = number / divisor;
		sprite_[i]->SetTextureRect({digit * size.x, 0.0f}, size);
		number %= divisor;
		divisor /= 10;
	}
}
