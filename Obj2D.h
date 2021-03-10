#pragma once

#include <string>

#include <include/glm.h>
#include <Core/GPU/Mesh.h>

namespace Obj2D
{

	// Create square with given bottom left corner, length and color
	Mesh* CreateSquare(std::string name, glm::vec3 leftBottomCorner, float length, float width, glm::vec3 color, bool fill = false);
	Mesh* CreateSemiCircle(std::string name, float length, glm::vec3 color);
	Mesh* CreateTriangle(std::string name, int x, int y, float length, glm::vec3 color);
	Mesh* CreateCircle(std::string name,float lenght, glm::vec3 color);
	Mesh* CreateLine(std::string name, glm::vec3 color);
	Mesh* Createshuriken(std::string name, glm::vec3 color);
	Mesh* CreateArrow(std::string name, float length, float width, glm::vec3 color,bool fill);

}

