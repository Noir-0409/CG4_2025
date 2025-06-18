#include "Particle.h"
#include "Model2.h"

void Particle::Initialize(Model2* model) {

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
