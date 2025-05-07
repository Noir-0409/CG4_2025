#include "Particle.h"

using namespace MathUtility;

void Particle::Initialize(Model* model) {

	assert(model);

	model_ = model; 

	worldTransform_.Initialize();

	//色の設定
	objectColor_.Initialize();
	color_ = {1, 1, 0, 1};

}

void Particle::Update() {

//行列を定数バッファに転送
	//worldTransform_.TransferMatrix();

	//移動
worldTransform_.translation_ += {0.0f, 0.1f, 0.0f};

//色変更オブジェクトに色の数値を設定
	objectColor_.SetColor(color_);

	worldTransform_.UpdateMatrix();

}

void Particle::Draw(Camera& camera) {

	model_->Draw(worldTransform_, camera, &objectColor_);


}
