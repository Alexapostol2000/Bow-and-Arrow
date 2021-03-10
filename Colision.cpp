#include "Colision.h"
#include <vector>
#include <iostream>
#include <Core/Engine.h>
#include <math.h>

using namespace std;
bool Colision::colisionarc(float r1,float r2,float x1, float x2, float y1, float y2) {
	

	float dx = x1 - x2;
	float dy = y1 - y2;
	float distance = sqrt(dx * dx + dy * dy);

	if (distance < r1 + r2) {
		return true;
	}
	else {
		return false;
	}
}

bool Colision::colisionsageata(float r1, float x1, float y1, float x2, float y2) {
	float dx = x2 - x1;
	float dy = y2 - y1;
	float distance = sqrt(dx * dx + dy * dy);

	if (r1 >= distance) {
		return true;
	}

	return false;
}