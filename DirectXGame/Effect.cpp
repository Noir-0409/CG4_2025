#include "Effect.h"
#include <random>
#include <algorithm>
#include "RandomUtility.h"

void Effect::Initialize(Model* model, Vector3 position) {

	assert(model);
	model_ = model;
	worldTransform_.Initialize();

	objectColor_.Initialize();
	color_ = {1, 1, 1, 1};
	float xScale = RandomUtility::GetXScale();
	float yScale = RandomUtility::GetYScale();
	float zScale = RandomUtility::GetZScale();
	float zRotation = RandomUtility::GetZRotation();

	worldTransform_.translation_ = position;
	worldTransform_.scale_ = {xScale, yScale, zScale};
	worldTransform_.rotation_ = {0.3f, 0.0f, zRotation};
}

void Effect::Update() { 

	if (isFinished_) {
	
		return;
	
	}

	objectColor_.SetColor(color_);

	color_.w = std::clamp(1.0f - counter_ / kDuration, 0.0f, 1.0f);

	worldTransform_.rotation_.z += 0.05f;

	counter_ += 1.0f / 60.0f;

	if (counter_ >= kDuration) {
	
	counter_ = kDuration;

	isFinished_ = true;
	
	}

	worldTransform_.UpdateMatrix();

}

void Effect::Draw(Camera& camera) { model_->Draw(worldTransform_, camera,&objectColor_); }
