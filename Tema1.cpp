#include "Tema1.h"
#include <vector>
#include <iostream>
#include <Core/Engine.h>
#include "Trans2D.h"
#include "Obj2D.h"
#include "Colision.h"
#include <math.h>
using namespace std;


float squareSide = 150;
float width = 10;
int x = 30, y = 15;
int txarc = 50, tyarc = 500, txsageatal = txarc, tysageatal = tyarc;
int value = txarc +2*( squareSide - 70);
int txc1 = value, tyc1 = 0 - rand() % 100,txc2= txc1 + 100,tyc2 = 0 - rand() % 100;
int txlc1= txc1 - (squareSide / 4), tylc1= tyc1 - (squareSide / 2) ,txlc2 = txc2-(squareSide/4) ,tylc2=tyc2-(squareSide/2);
int txs=-1,tys=-1,tx7= txarc/2,ty7=tyarc-(squareSide/2)-10;
int speed = 0, score = 0, vieti = 3, time = 0;
bool ok = false, wait = false, press = false, l1 = false,l2=false;
float d1, d2, rad,rads,sc1,sc2;
float rsuriken = sqrt(800) ,rarc= squareSide /2,rsageata=50,rbalon= squareSide / 4;
int scale;
Tema1::Tema1()
{
}

Tema1::~Tema1()
{
}

void Tema1::Init()
{
	glm::ivec2 resolution = window->GetResolution();
	auto camera = GetSceneCamera();
	camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
	camera->SetPosition(glm::vec3(0, 0, 50));
	camera->SetRotation(glm::vec3(0, 0, 0));
	camera->Update();
	GetCameraInput()->SetActive(false);
		
	glm::vec3 corner = glm::vec3(0, 0, 0);
	
	Mesh* square2 = Obj2D::CreateSquare("square2", corner, width-5 , squareSide - 30, glm::vec3(0, 0, 0), true);
	AddMeshToList(square2);
	Mesh* semicircle1 = Obj2D::CreateSemiCircle("semicircle1", squareSide, glm::vec3(0, 0, 0));
	AddMeshToList(semicircle1);
	Mesh* arrow = Obj2D::CreateArrow("arrow",width-5, squareSide-70, glm::vec3(0, 0, 0),true);
	AddMeshToList(arrow);
	Mesh* circle1 = Obj2D::CreateCircle("circle1", squareSide/2,glm::vec3(1, 0, 0));
	AddMeshToList(circle1);
	Mesh* circle2 = Obj2D::CreateCircle("circle2", squareSide / 2, glm::vec3(1, 1, 0));
	AddMeshToList(circle2);
	Mesh* circle3 = Obj2D::CreateCircle("circle3", squareSide / 6, glm::vec3(0, 1, 0));
	AddMeshToList(circle3);
	Mesh* line1 = Obj2D::CreateLine("line1", glm::vec3(0, 0, 0));
	AddMeshToList(line1);
	Mesh* line2 = Obj2D::CreateLine("line2", glm::vec3(0, 0, 0));
	AddMeshToList(line2);
	Mesh* shuriken1 = Obj2D::Createshuriken("shuriken1", glm::vec3(0, 0, 0));
	AddMeshToList(shuriken1);
}	

void Tema1::FrameStart()
{
	// clears the color buffer (using the previously set color) and depth buffer
	glClearColor(255, 255, 255, 255);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::ivec2 resolution = window->GetResolution();
	// sets the screen area where to draw
	glViewport(0, 0, resolution.x, resolution.y);
}



void Tema1::Update(float deltaTimeSeconds)
{
	glLineWidth(5);
	glPointSize(5);
	glm::ivec2 resolution = window->GetResolution();
	glViewport(0, 0, resolution.x, resolution.y);
	
	// Scalare balon doborat //
	if (l1 == true ) {
		modelMatrix = glm::mat3(1);
		modelMatrix *= Trans2D::Translate(txc1, tyc1);
		modelMatrix *= Trans2D::Scale(sc1, sc1);
		RenderMesh2D(meshes["circle1"], shaders["VertexColor"], modelMatrix);

		modelMatrix = glm::mat3(1);
		modelMatrix *= Trans2D::Translate(txlc1, tylc1);
		modelMatrix *= Trans2D::Scale(sc1, sc1);
		RenderMesh2D(meshes["line1"], shaders["VertexColor"], modelMatrix);
		if (sc1 > 0) { 
			sc1 -= deltaTimeSeconds*5; 
		}else {
			l1 = false;
			tyc1 = 0 - rand() % 300;
			tylc1 = tyc1 - (squareSide / 2) - 20;
			txc1 = rand() % resolution.x + value;
			txlc1 = txc1 - (squareSide / 4);
		}
	}

	if (l2 == true ) {
		modelMatrix = glm::mat3(1);
		modelMatrix *= Trans2D::Translate(txc2, tyc2);
		modelMatrix *= Trans2D::Scale(sc2, sc2);
		RenderMesh2D(meshes["circle2"], shaders["VertexColor"], modelMatrix);

		modelMatrix = glm::mat3(1);
		modelMatrix *= Trans2D::Translate(txlc2, tylc2);
		modelMatrix *= Trans2D::Scale(sc2, sc2);
		RenderMesh2D(meshes["line2"], shaders["VertexColor"], modelMatrix);
		if (sc2 > 0) {
			sc2 -= deltaTimeSeconds * 5;
		}
		else {
			l2 = false;
			tyc2 = 0 - rand() % 300;
			tylc2 = tyc2 - (squareSide / 2) - 20;
			txc2 = rand() % resolution.x + value;
			txlc2 = txc2 - (squareSide / 4);
		}
	}
	 // Terminare Scalare balon doborat //

	// Miscare balon + respawn//
	if (tylc2 < resolution.y&& l2 == false) {
		tyc2 += deltaTimeSeconds * 300;
		tylc2 += deltaTimeSeconds * 300;
	}
	if(tylc2 >= resolution.y) {
		tyc2 = 0 - rand() % 300;
		tylc2 = tyc2 - (squareSide / 2) - 20;
		txc2 = rand() % resolution.x + value;
		txlc2 = txc2 - (squareSide / 4);
	}

	if (tylc1 < resolution.y && l1 == false ) {
		tyc1 += deltaTimeSeconds * 300;
		tylc1 += deltaTimeSeconds * 300;
	}
	if(tylc1 >= resolution.y) {
		tyc1 = 0 - rand() % 300;
		tylc1 = tyc1 - (squareSide / 2) - 20;
		txc1 = rand() % resolution.x + value;
		txlc1 = txc1 - (squareSide / 4);
	}
	// final miscare balon //
	

	// miscare suriken //
	if (txs < 0) {
		txs = resolution.x;
		tys = rand() % (resolution.y - 200) ;
	}
	else {
		txs -= deltaTimeSeconds * 300;
		angularStep += deltaTimeSeconds;
	}
	// finish miscare suriken

	// miscare seageata //
	if (txsageatal < resolution.x && tysageatal < resolution.y && tysageatal > -10 && ok == true) {
		txsageatal += speed * cos(rads);
		tysageatal += speed * sin(rads);
	}
	else {
		if (ok == true) {
			speed = 0;
			ok = false;
			wait = true;
		}
	}
	if (wait == true) {
		time += 1;
		if (time > 30) {
			wait = false;
			time = 0;
			txsageatal = txarc;
			tysageatal = tyarc;

		}
	}
	// finish miscare sageata //

	// vieti //
	for (int i = 1; i <= vieti; i++) {
		
		modelMatrix = glm::mat3(1);
		modelMatrix *= Trans2D::Translate(i*30, resolution.y - 20);
		RenderMesh2D(meshes["circle3"], shaders["VertexColor"], modelMatrix);
	}
	// finish vieti //

	// powerbar //
	
	modelMatrix = glm::mat3(1);
	modelMatrix *= Trans2D::Translate(tx7, ty7);
	
	if (press == false) {
		modelMatrix *= Trans2D::Scale(0, 0);
		scale = 0;
	}else{
		modelMatrix *= Trans2D::Scale(scale/ squareSide, 1.5);
	}
	
	RenderMesh2D(meshes["square2"], shaders["VertexColor"], modelMatrix);
	
	// finish powerbar //

	//	arc //

	modelMatrix = glm::mat3(1);
	modelMatrix *= Trans2D::Translate(txarc, tyarc);
	modelMatrix *= Trans2D::Rotate(rad);
	RenderMesh2D(meshes["semicircle1"], shaders["VertexColor"], modelMatrix);
	
	// finish arc // 
	
	// sageata //

	modelMatrix = glm::mat3(1);
	modelMatrix *= Trans2D::Translate(txsageatal, tysageatal);
	if (ok == false && wait == false) {
		modelMatrix *= Trans2D::Rotate(rad);
	}
	else {
		modelMatrix *= Trans2D::Rotate(rads);
	}
	RenderMesh2D(meshes["arrow"], shaders["VertexColor"], modelMatrix);
	// finish sageata //
	
	// balon1 //
	if (l1 == false) {
		modelMatrix = glm::mat3(1);
		modelMatrix *= Trans2D::Scale(1, 1);
		modelMatrix *= Trans2D::Translate(txc1, tyc1);
		RenderMesh2D(meshes["circle1"], shaders["VertexColor"], modelMatrix);

		modelMatrix = glm::mat3(1);
		modelMatrix *= Trans2D::Translate(txlc1, tylc1);
		modelMatrix *= Trans2D::Scale(1, 1);
		RenderMesh2D(meshes["line1"], shaders["VertexColor"], modelMatrix);
	}
	// finish balon1 //

	// balon2 //
	if (l2 == false) {
		modelMatrix = glm::mat3(1);
		modelMatrix *= Trans2D::Scale(1, 1);
		modelMatrix *= Trans2D::Translate(txc2, tyc2);
		RenderMesh2D(meshes["circle2"], shaders["VertexColor"], modelMatrix);

		modelMatrix = glm::mat3(1);
		modelMatrix *= Trans2D::Scale(1, 1);
		modelMatrix *= Trans2D::Translate(txlc2, tylc2);
		RenderMesh2D(meshes["line2"], shaders["VertexColor"], modelMatrix);
	}
	// finish balon 2 //
	
	// suriken //
	modelMatrix = glm::mat3(1);
	modelMatrix *= Trans2D::Translate(txs, tys);
	modelMatrix *= Trans2D::Rotate(angularStep * 5);
	modelMatrix *= Trans2D::Translate(-40, -60);
	RenderMesh2D(meshes["shuriken1"], shaders["VertexColor"], modelMatrix);
	// finish suriken //

	// colision arc cu suriken //
	if (Colision::colisionarc(rarc, rsuriken, txarc, txs, tyarc, tys)) {
		vieti--;
		txs = resolution.x;
		tys = rand() % (resolution.y - 200);
		if (vieti == 0) {
			cout << "Ai pierdut si scorul final este " << score << endl;
			exit(0);
		}
	}

	// final coliziune //
	
	// colision sageata cu balon rosu //
	if (Colision::colisionsageata(rbalon, txsageatal + 60, tysageatal + 10, txc1, tyc1) && l1 == false) {
		score++;
		cout << "New score :" << score<<endl;
		l1 = true;
		sc1 = 1;
	}
	// colision sageata cu balon galben //
	if (Colision::colisionsageata(rbalon, txsageatal + 60, tysageatal + 10, txc2, tyc2) && l2 == false) {
		score--;
		cout << "New score :" << score<<endl;
		l2 = true;
		sc2 = 1;
	}
	// final coliziune cu baloane //

	// colision sageata cu suriken //
	if (Colision::colisionsageata(rsuriken, txsageatal+60, tysageatal+10, txs, tys)) {
		txs = resolution.x;
		tys = rand() % (resolution.y - 200);
		score++;
		cout << "New score :" << score << endl;
	}
	//final coliziune cu suriken //


	
}

void Tema1::FrameEnd()
{

}

void Tema1::OnInputUpdate(float deltaTime, int mods)
{
	glm::ivec2 resolution = window->GetResolution();
	glViewport(0, 0, resolution.x, resolution.y);
	if (window->KeyHold(GLFW_KEY_W)&&tyarc<resolution.y-(squareSide/2)) {
		if (tyarc < resolution.y) {
			tyarc += deltaTime * 200;
			ty7 += deltaTime * 200;
		}
		if (ok == false && wait == false) {
			tysageatal += deltaTime * 200;
		}
		}
	if (window->KeyHold(GLFW_KEY_S) && tyarc>squareSide/2) {
			tyarc -= deltaTime * 200;
			ty7 -= deltaTime * 200;
		if (ok == false && wait == false) {
			tysageatal -= deltaTime * 200;
		}
	}
	if (window->MouseHold(GLFW_MOUSE_BUTTON_1)) {
		if (speed < 70 && ok == false) {
			press = true;
			speed += deltaTime * 125;
			scale = speed;
		}
	}
		
	
}

void Tema1::OnKeyPress(int key, int mods)
{
	// add key press event
}

void Tema1::OnKeyRelease(int key, int mods)
{
	// add key release event
}

void Tema1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
	glm::ivec2 resolution = window->GetResolution();
	glViewport(0, 0, resolution.x, resolution.y);
	d1 = mouseX - txarc;
	d2 = resolution.y - mouseY - tyarc;
	rad = glm::atan((float)d2, (float)d1);
}

void Tema1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button press event
}

void Tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
	press = false;
	ok = true;
	if (txsageatal < txarc + squareSide - 140) {
		rads = rad;
	}
}


void Tema1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}

void Tema1::OnWindowResize(int width, int height)
{
}
