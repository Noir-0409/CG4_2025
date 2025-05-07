#include "Particle.h"

void Particle::Initialize(Model* model) {

	assert(model);

	model_ = model;

	worldTransform_.Initialize();

}

void Particle::Update() {

	// 行列を定数バッファに転送
	worldTransform_.TransferMatrix();

}

void Particle::Draw(Camera& camera) { 
	
	model_->Draw(worldTransform_, camera);

}
