#include "GameScene.h"
#include <random>

using namespace MathUtility;

std::random_device seedGenerator;
std::mt19937 randomEngine(seedGenerator());
std::uniform_real_distribution<float> distribution(-1.0f, 1.0f);

GameScene::~GameScene() {

	delete modelParticle_;
	delete particle_;
}

void GameScene::Initialize() {

	// モデルデータ生成
	modelParticle_ = Model::CreateSphere(4, 4);

	// カメラの初期化
	camera_.Initialize();

	//乱数の初期化
	srand((unsigned)time(NULL));

}

void GameScene::Update() {

	for (Particle* particle : particles_) {

		particle->Update();
	}

	//確率で発生
	if (rand() % 20 == 0) {
	
		// 発生位置は乱数
		Vector3 position = {distribution(randomEngine) * 30.0f, distribution(randomEngine) * 20.0f, 0};

		ParticleBorn(position);
	
	}

	// 終了フラグの立ったパーティクルを削除
	particles_.remove_if([](Particle* particle) {
		if (particle->IsFinished()) {

			delete particle;

			return true;
		}

		return false;
	});
}

void GameScene::Draw() {

	// DirectXCommonインスタンスの所得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	// 3Dモデル描画前処理
	Model::PreDraw(dxCommon->GetCommandList());

	for (Particle* particle : particles_) {

		particle->Draw(camera_);
	}

	// 3Dモデル描画後処理
	Model::PostDraw();
}

void GameScene::ParticleBorn(Vector3 position) {

	// パーティクルの生成
	for (int i = 0; i < 150; i++) {

		// 生成
		Particle* particle = new Particle();

		// 移動量
		Vector3 velocity = {distribution(randomEngine), distribution(randomEngine), 0};

		Normalize(velocity);
		velocity *= distribution(randomEngine);
		velocity *= 0.1f;

		// 初期化
		particle->Initialize(modelParticle_, position, velocity);

		// リストに追加
		particles_.push_back(particle);
	}
}
