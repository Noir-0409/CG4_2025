#include "Particle.h"

using namespace MathUtility;

void Particle::Initialize(Model* model, Vector3 position) {

	assert(model);

	model_ = model;

	worldTransform_.Initialize();

	// 色の設定
	objectColor_.Initialize();
	color_ = {1, 1, 0, 1};

	worldTransform_.translation_ = position;
}

void Particle::Update() {

	// 移動
	worldTransform_.translation_ += {0.0f, 0.1f, 0.0f};

	// 色変更オブジェクトに色の数値を設定
	objectColor_.SetColor(color_);

	worldTransform_.UpdateMatrix();
}

void Particle::Draw(Camera& camera) { model_->Draw(worldTransform_, camera, &objectColor_); }
