#include "RandomUtility.h"

namespace {
std::random_device rd;
std::mt19937 mt(rd());
std::uniform_real_distribution<float> yScaleDist(20.0f, 25.0f);
std::uniform_real_distribution<float> zRotDist(-3.14159f, 3.14159f);
std::uniform_real_distribution<float> xScaleDist(3.0f, 10.0f);
std::uniform_real_distribution<float> zScaleDist(0.5f, 2.0f);
}

float RandomUtility::GetFloat(float min, float max) {
	std::uniform_real_distribution<float> dist(min, max);
	return dist(mt);
}

Vector3 RandomUtility::GetRandomPosition(float xRange, float yRange) { return {GetFloat(-xRange, xRange), GetFloat(-yRange, yRange), 0.0f}; }

float RandomUtility::GetYScale() { return yScaleDist(mt); }

float RandomUtility::GetZRotation() { return zRotDist(mt); }

float RandomUtility::GetXScale() { return xScaleDist(mt); }

float RandomUtility::GetZScale() { return zScaleDist(mt); }
