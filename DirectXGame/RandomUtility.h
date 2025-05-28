#pragma once
#include <random>
#include <KamataEngine.h>

using namespace KamataEngine;

class RandomUtility {
public:
	static float GetFloat(float min, float max);
	static Vector3 GetRandomPosition(float xRange, float yRange);
	static float GetYScale();
	static float GetZRotation();

};