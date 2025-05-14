#include "Particle.h"
#include <algorithm>

using namespace MathUtility;

void Particle::Initialize(Model* model, Vector3 position, Vector3 velocity) {

	assert(model);

	model_ = model;

	worldTransform_.Initialize();

	// 色の設定
	objectColor_.Initialize();
	color_ = {1, 1, 0, 1};

	worldTransform_.translation_ = position;
	worldTransform_.scale_ = {0.2f, 0.2f, 0.2f};

	velocity_ = velocity;
}

void Particle::Update() {

	// 移動
	worldTransform_.translation_ += velocity_;

	// 色変更オブジェクトに色の数値を設定
	objectColor_.SetColor(color_);

	// 終了ならなにもしない
	if (isFinished_) {

		return;
	}

	// カウンターをフレーム分進める
	counter_ += 1.0f / 60.0f;

	// 持続時間の上限に達したら
	if (counter_ >= kDuration) {

		counter_ = kDuration;

		// 終了扱いにする
		isFinished_ = true;
	}

	// フェード処理
	color_.w = std::clamp(1.0f - counter_ / kDuration, 0.0f, 1.0f);

	worldTransform_.UpdateMatrix();
}

void Particle::Draw(Camera& camera) { model_->Draw(worldTransform_, camera, &objectColor_); }
