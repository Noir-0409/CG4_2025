#include "GameScene.h"
#include <json.hpp>
#include <fstream>	
#include <string>

GameScene::~GameScene() {}

void GameScene::Initialize() {

	const std::string fullpath = std::string("Resources/levels/") + "adoon.json";

	std::ifstream file;

	file.open(fullpath);

	if (file.fail()) {
	
		assert(0);
	
	}

	nlohmann::json deserialized;

	file >> deserialized;

	assert(deserialized.is_object());
	assert(deserialized.contains("name"));
	assert(deserialized["name"].is_string());

	std::string name = deserialized["name"].get<std::string>();

	assert(name.compare("scene") == 0);

	levelData = new LevelData();

	for (nlohmann::json& object : deserialized["objects"]) {
	
		assert(object.contains("type"));

		std::string type = object["type"].get<std::string>();

		if (type.compare("MESH") == 0) {
		
			levelData->objects.emplace_back(LevelData::ObjectData{});

			LevelData::ObjectData& objectData = levelData->objects.back();

			if (object.contains("file_name")) {
			
				objectData.fileName = object["file_name"];
			
			}

			nlohmann::json& transform = object["transform"];

			objectData.translation.x = (float)transform["translation"][0];
			objectData.translation.y = (float)transform["translation"][2];
			objectData.translation.z = (float)transform["translation"][1];

			objectData.rotation.x = -(float)transform["rotation"][0];
			objectData.rotation.y = -(float)transform["rotation"][2];
			objectData.rotation.z = -(float)transform["rotation"][1];

			objectData.scaling.x = (float)transform["scaling"][0];
			objectData.scaling.y = (float)transform["scaling"][2];
			objectData.scaling.z = (float)transform["scaling"][1];
		
		}
	
		//if (object.contains("children"));


	}

	for (auto& objectData : levelData->objects) {
	
		Model* model = nullptr;
		decltype(models)::iterator it = models.find(objectData.fileName);
		if (it != models.end()) {
			Model* model = Model::CreateFromOBJ(objectData.fileName);
			models[objectData.fileName] = model;
		}

		WorldTransform* newObject = new WorldTransform();
		newObject->translation_ = objectData.translation;
		newObject->rotation_ = objectData.rotation;
		newObject->scale_ = objectData.scaling;

		newObject->Initialize();

		worldTransforms.push_back(newObject);

	}

	camera.Initialize();

}

void GameScene::Update() { 

	for (WorldTransform* object : worldTransforms) {
	
		object->TransferMatrix();
	
	}

}

void GameScene::Draw() {

	// DirectXCommonインスタンスの所得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	// 3Dモデル描画前処理
	Model::PreDraw(dxCommon->GetCommandList());

	int i = 0;

	for (auto& objectData : levelData->objects) {

		Model* model = nullptr;
		decltype(models)::iterator it = models.find(objectData.fileName);
		if (it != models.end()) {
			model = it->second;
		}

		if (model) {
			model->Draw(*worldTransforms[i], camera);
		}

		i++;

	}

	// 3Dモデル描画後処理
	Model::PostDraw();
}
