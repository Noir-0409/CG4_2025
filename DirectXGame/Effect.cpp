#include "Effect.h"
#include <random>

std::random_device seedGenerator;
std::mt19937 randomEngine(seedGenerator());
std::uniform_real_distribution<float> yScaleDist(0.5f, 5.0f);
std::uniform_real_distribution<float> zRotDist(-3.14159f, 3.14159f);

void Effect::Initialize(Model* model) {

	assert(model);
	model_ = model;
	worldTransform_.Initialize();
	float yScale = yScaleDist(randomEngine);
	float zRotation = zRotDist(randomEngine);

	worldTransform_.scale_ = {1.0f, yScale, 0.1f};
	worldTransform_.rotation_ = {0.0f, 0.0f, zRotation};
}

void Effect::Update() { 

	worldTransform_.UpdateMatrix();

}

void Effect::Draw(Camera& camera) { model_->Draw(worldTransform_, camera); }
