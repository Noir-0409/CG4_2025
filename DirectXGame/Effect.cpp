#include "Effect.h"
#include <random>
#include <algorithm>

std::random_device seedGenerator;
std::mt19937 randomEngine(seedGenerator());
std::uniform_real_distribution<float> yScaleDist(0.3f, 3.0f);
std::uniform_real_distribution<float> zRotDist(-3.14159f, 3.14159f);

void Effect::Initialize(Model* model) {

	assert(model);
	model_ = model;
	worldTransform_.Initialize();

	objectColor_.Initialize();
	color_ = {1, 1, 1, 1};

	float yScale = yScaleDist(randomEngine);
	float zRotation = zRotDist(randomEngine);

	worldTransform_.scale_ = {1.0f, yScale, 0.1f};
	worldTransform_.rotation_ = {0.0f, 0.0f, zRotation};
}

void Effect::Update() { 

	if (isFinished_) {
	
		return;
	
	}

	objectColor_.SetColor(color_);

	color_.w = std::clamp(1.0f - counter_ / kDuration, 0.0f, 1.0f);

	counter_ += 1.0f / 60.0f;

	if (counter_ >= kDuration) {
	
	counter_ = kDuration;

	isFinished_ = true;
	
	}

	worldTransform_.UpdateMatrix();

}

void Effect::Draw(Camera& camera) { model_->Draw(worldTransform_, camera,&objectColor_); }
