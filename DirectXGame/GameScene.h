#pragma once
#include "3d/Model.h"
#include "KamataEngine.h"
#include "Particle.h"
#include <map>
#include <vector>

using namespace KamataEngine;

// ゲームシーン
class GameScene {

	struct LevelData {

		struct ObjectData {

			std::string fileName;
			Vector3 translation;
			Vector3 rotation;
			Vector3 scaling;
		};

		std::vector<ObjectData> objects;
	};

public:
	~GameScene();

	// 初期化
	void Initialize();

	// 更新
	void Update();

	// 描画
	void Draw();

private:
	LevelData* levelData = nullptr;

	std::map<std::string, Model*> models;

	std::vector<WorldTransform*> objects;

	Camera camera;

};