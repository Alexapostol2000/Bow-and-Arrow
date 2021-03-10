#pragma once

#include <string>
#include <include/glm.h>
#include <Core/GPU/Mesh.h>

namespace Colision
{
	bool colisionarc(float r1, float r2, float x1, float x2, float y1, float y2);
	bool colisionsageata(float r1, float x1, float y1, float x2, float y2);
}