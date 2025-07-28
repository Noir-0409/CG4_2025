#pragma once

class Graph {

public:

~Graph();

void Initialize();

void Update(float deltaTime);

void Draw();

private:

	float elapsedTime_;
	float duration_; 

	int currentR_, currentG_, currentB_;

};