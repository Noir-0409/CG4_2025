#include "GameScene.h"
#include <random>
#include "RandomUtility.h"

GameScene::GameScene() {}

GameScene::~GameScene() {

	delete modelEffect_;
	for (Effect* effects : effects_) {

		delete effects;
	}
}

void GameScene::Initialize() {

	modelEffect_ = Model::CreateFromOBJ("effect", true);

	camera_.Initialize();

	srand((unsigned)time(NULL));

}

void GameScene::Update() {
	for (Effect* effects : effects_) {

		effects->Update();

	}

	effects_.remove_if([](Effect* effect) {

		if (effect->IsFinished()) {
		
		delete effect;

		return true;
		
		}

		return false;

	});

	if (rand() % 20 == 0) {

		Vector3 position = RandomUtility::GetRandomPosition(30.0f, 20.0f);

		EffectBorn(position);
	}

}

void GameScene::Draw() {

	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Model::PreDraw(dxCommon->GetCommandList());

	for (Effect* effects : effects_) {

		effects->Draw(camera_);
	}

	Model::PostDraw();
}

void GameScene::EffectBorn(Vector3 position) {

		for (int i = 0; i < 40; i++) {

		Effect* effects = new Effect();
		effects->Initialize(modelEffect_,position);
		effects_.push_back(effects);
	}

}
