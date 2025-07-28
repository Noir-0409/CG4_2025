#include "Graph.h"

Graph::~Graph() {}

void Graph::Initialize() {

	elapsedTime_ = 0.0f;
	duration_ = 10.0f;
}

void Graph::Update(float deltaTime) {

	elapsedTime_ += deltaTime;
	if (elapsedTime_ > duration_)
		elapsedTime_ = duration_;
}

void Graph::Draw() {}
