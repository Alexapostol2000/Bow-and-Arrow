#include "Obj2D.h"
#include <vector>
#include <iostream>
#include <Core/Engine.h>

Mesh* Obj2D::CreateSquare(std::string name, glm::vec3 leftBottomCorner, float length,float width, glm::vec3 color, bool fill)
{
	glm::vec3 corner = leftBottomCorner;

	std::vector<VertexFormat> vertices =
	{
		VertexFormat(glm::vec3(0,0,0), color),
		VertexFormat(glm::vec3(width, 0, 0), color),
		VertexFormat(glm::vec3(width, length, 0), color),
		VertexFormat(glm::vec3(0, length, 0), color)
	};

	Mesh* square = new Mesh(name);
	std::vector<unsigned short> indices = { 0, 1, 2, 3 };
	
	if (!fill) {
		square->SetDrawMode(GL_LINE_LOOP);
	}
	else {
		// draw 2 triangles. Add the remaining 2 indices
		indices.push_back(0);
		indices.push_back(2);
	}

	square->InitFromData(vertices, indices);
	return square;
}

Mesh* Obj2D::CreateArrow(std::string name, float height, float width, glm::vec3 color, bool fill)
{
	std::vector<VertexFormat> vertices =
	{
		VertexFormat(glm::vec3(0, height + 2, 0), color),
		VertexFormat(glm::vec3(0, height + 4, 0), color),
		VertexFormat(glm::vec3(width, height + 4, 0), color),
		VertexFormat(glm::vec3(width, height + 2, 0), color),
		VertexFormat(glm::vec3(width, height + 12, 0), color),
		VertexFormat(glm::vec3(width + 20, height + 3, 0), color),
		VertexFormat(glm::vec3(width, 0, 0), color),
	};

	Mesh* square = new Mesh(name);
	std::vector<unsigned short> indices = { 0, 1, 2, 3, 0, 2, 4, 6, 5 };



	square->InitFromData(vertices, indices);
	return square;
}

Mesh* Obj2D::CreateSemiCircle(std::string name,float length,glm::vec3 color) {
	std::vector<VertexFormat> vertices;
	std::vector<GLushort> indices;
	float radius = length /2;
	int j = 0;
	float PI = 3.14159265358979323846;
	for (float i = 0.0; i <=	PI; i += 0.001) {
		vertices.emplace_back(glm::vec3(sin(i) * radius/2, cos(i) * radius, 0), color);
		indices.emplace_back(j);
		j++;
	}
	Mesh* circle = new Mesh(name);
	circle->SetDrawMode(GL_LINE_LOOP);
	circle->InitFromData(vertices, indices);
	return circle;
}

Mesh* Obj2D::CreateTriangle(std::string name,int x,int y, float length, glm::vec3 color) {
	std::vector<VertexFormat> vertices =
	{
		VertexFormat(glm::vec3(0, 0, 0), color),
		VertexFormat(glm::vec3(y, y,0), color),
		VertexFormat(glm::vec3(0, x, 0), color),
	};

	std::vector<unsigned short> indices = {0,1,2};

	Mesh* triangle = new Mesh(name);
	triangle->InitFromData(vertices, indices);
	return triangle;
}

Mesh* Obj2D::CreateCircle(std::string name,float lenght, glm::vec3 color) {
	std::vector<VertexFormat> vertices;
	std::vector<GLushort> indices;
	float radius = lenght / 2;
	int j = 0;
	float PI = 2*3.14159265358979323846;
	for (float i = 0.0; i <= PI; i += 0.001) {
		vertices.emplace_back(glm::vec3(sin(i) * radius, cos(i) * radius, 0), color);
		indices.emplace_back(j);
		j++;
	}
	Mesh* circle = new Mesh(name);
	circle->SetDrawMode(GL_POLYGON);
	circle->InitFromData(vertices, indices);
	return circle;
}
Mesh* Obj2D::CreateLine(std::string name, glm::vec3 color) {
	std::vector<VertexFormat> vertices =
	{
		VertexFormat(glm::vec3(50, 50, 0), color),
		VertexFormat(glm::vec3(40, 40,0), color),
		VertexFormat(glm::vec3(60, 30, 0), color),
		VertexFormat(glm::vec3(50, 0,0), color),
	};

	std::vector<unsigned short> indices = { 0, 1, 1, 2, 2 ,3 };

	Mesh* line = new Mesh(name);
	line->InitFromData(vertices, indices);
	line->SetDrawMode(GL_LINES);
	return line;
}



Mesh* Obj2D::Createshuriken(std::string name, glm::vec3 color) {
	std::vector<VertexFormat> vertices =
	{
		VertexFormat(glm::vec3(20, 80, 0), color),
		VertexFormat(glm::vec3(40, 80,0), color),
		VertexFormat(glm::vec3(40, 60, 0), color),
		VertexFormat(glm::vec3(60,80,0), color),
		VertexFormat(glm::vec3(60, 60, 0), color),
		VertexFormat(glm::vec3(60, 40,0), color),
		VertexFormat(glm::vec3(40, 40, 0), color),
		VertexFormat(glm::vec3(20,40,0), color),
		VertexFormat(glm::vec3(20,60,0), color),
	};

	std::vector<unsigned short> indices = {0,1,2,3,4,2,5,6,2,7,2,8};

	Mesh* shuriken = new Mesh(name);
	shuriken->InitFromData(vertices, indices);
	return shuriken;
}