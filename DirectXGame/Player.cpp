#include "Player.h"

using namespace KamataEngine;

Player::~Player() {}

void Player::Initialize(Model* model) {

	assert(model);

	model_ = model;

	worldTransform_.Initialize();

}

void Player::Update() {

	worldTransform_.TransferMatrix();

}

void Player::Draw(Camera& camera) {

	model_->Draw(worldTransform_, camera);

}
