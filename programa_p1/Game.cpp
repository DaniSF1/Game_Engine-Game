#include "Game.h"
#include "Text.h"
#include "Interfaz.h"
#include <iostream>
#include <vector>
#include <sstream>

void Game::ProcessKeyPressed(unsigned char key, int px, int py)
{
	// de momento no hacemos nada
	std::cout << "Tecla pulsada: " << key << std::endl;
	if (key == 'w' || key == 'W')
	{
		this->player->SetSpeed(
			Vector3D(
				this->player->GetSpeedX(),
				this->player->GetSpeedY() + 0.01,
				this->player->GetSpeedZ()));

	}
	else if (key == 's' || key == 'S')
	{
		this->player->SetSpeed(
			Vector3D(
				this->player->GetSpeedX(),
				this->player->GetSpeedY() - 0.01,
				this->player->GetSpeedZ()));
	}
	else if (key == 'a' || key == 'A')
	{
		this->player->SetSpeed(
			Vector3D(
				this->player->GetSpeedX() - 0.01,
				this->player->GetSpeedY(),
				this->player->GetSpeedZ()));
	}
	else if (key == 'd' || key == 'D')
	{
		this->player->SetSpeed(
			Vector3D(
				this->player->GetSpeedX() + 0.01,
				this->player->GetSpeedY(),
				this->player->GetSpeedZ()));
	}
}

void Game::ProcessMouseMovement(int x, int y)
{
	// de momento no hacemos nada
	std::cout << "Movimiento del raton: " << x << ", " << y << std::endl;
}

void Game::ProcessMouseClick(int button, int state, int x, int y)
{
	std::cout << "Clic: " << button << std::endl;
	if (activeScene == sceneInic) 
	{
		if (button == 0 && state == 1) {
			activeScene = sceneL1;
		}
	}
	else if (activeScene == sceneTitulo) {
		if (button == 0 && state == 1) {
			activeScene = sceneInic;
		}
	}
}

void Game::GenerarObjeto()
{
	int n = GenerateRandom(1, 10);

	if (n == 1)
	{
		sceneL1->AddGameObject(lifeToGenerate->GenerarVida());
	}
	else if (n == 2)
	{
		sceneL1->AddGameObject(ammuToGenerate->GenerateMun());
	}
	else
	{
		sceneL1->AddGameObject(obsToGenerate->GenerateObs());
	}
}

void Game::ControlFlujo()
{
	if (player->GetNivel() == 1) {
		if (segundos % 300 == 0) {
			GenerarObjeto();
		}
	}

	else if (player->GetNivel() == 2) {
		if (segundos % 200 == 0) {
			GenerarObjeto();
		}
	}

	else if (player->GetNivel() == 3)
	{
		if (segundos % 100 == 0) {
			GenerarObjeto();
		}
	}
	else if (player->GetNivel() == 4)
	{
		this->activeScene = sceneGanador;
	}
}

void Game::ControlNivel()
{
	if (segundos == 4000) {
		this->player->SetNivel(2);
	}
	else if (segundos == 10000) {
		this->player->SetNivel(3);
	}
	else if (segundos == 15000) {
		this->player->SetNivel(4);
	}
}

int Game::GenerateRandom(int min, int max)
{
	int random = rand() % max + min;
	return random;
}

void Game::Init()
{ 
	//Iniciamos camera
	Camera* camera = new Camera();
	camera->SetPosition(Vector3D(8.0, 5.0, 12.0));

	sceneTitulo->AddGameObject(camera);
	sceneInic->AddGameObject(camera);
	sceneL1->AddGameObject(camera);
	sceneGanador->AddGameObject(camera);
	sceneFin->AddGameObject(camera);

	//Inciamos el texto de nuestra pantalla de título
	Text* textP0 = new Text();
	string inic0 = "Space Traveler";
	textP0->SetPosition(Vector3D(5.0, 9.0, -20.0));
	textP0->SetColor(Color(0.0, 0.0, 0.0));
	textP0->setTexto(inic0);
	sceneTitulo->AddGameObject(textP0);

	//Iniciamos el texto de nuestra pantalla de instrucciones
	Text* textP1 = new Text();
	string inic = "Para ganar tienes que esquivar los distintos obstaculos que vayan apareciendo.";
	textP1->SetPosition(Vector3D(3.5, 9.0, 0.0));
	textP1->SetColor(Color(0.0, 0.0, 0.0));
	textP1->setTexto(inic);
	sceneInic->AddGameObject(textP1);

	Text* textP4 = new Text();
	string inic4 = "Los corazones te dan una vida y coge todas las cajas que puedas";
	textP4->SetPosition(Vector3D(4.0, 7.0, 0.0));
	textP4->SetColor(Color(0.0, 0.0, 0.0));
	textP4->setTexto(inic4);
	sceneInic->AddGameObject(textP4);

	//Iniciamos el texto de nuestra pantalla final
	Text* textP2 = new Text();
	string inic2 = "Has perdido, mas suerte la proxima vez";
	textP2->SetPosition(Vector3D(5.0, 9.0, 0.0));
	textP2->SetColor(Color(0.0, 0.0, 0.0));
	textP2->setTexto(inic2);
	sceneFin->AddGameObject(textP2);

	//Iniciamos el texto de ganador
	Text* textP3 = new Text();
	string inic3 = "Has ganado, enhorabuena";
	textP3->SetPosition(Vector3D(6.0, 9.0, 0.0));
	textP3->SetColor(Color(0.0, 0.0, 0.0));
	textP3->setTexto(inic3);
	sceneGanador->AddGameObject(textP3);

	this->activeScene = sceneTitulo;

	//Iniciamos el modelo del jugador
	ModelLoader* loader = new ModelLoader();
	loader->LoadModel("3dModels\\pru.obj");
	player = new Jugador(loader->getModel());
	this->player->SetPosition(Vector3D(8, 4, 0));
	this->player->SetRotation(Vector3D(180, 180, 0));
	this->player->SetSpeed(Vector3D(0.0, 0.0, 0.0));
	this->player->PaintColor(Color(0.8, 0.8, 0.9));
	sceneL1->AddGameObject(this->player);
	loader->Clear();

	//Iniciamos la interfaz
	Interfaz* interfaz = new Interfaz(player);
	sceneL1->AddGameObject(interfaz);

	Cylinder* borde1 = new Cylinder();
	borde1->SetRadioB(0.4);
	borde1->SetRadioPS(0.4);
	borde1->SetHeight(200);
	borde1->SetSlices(30);
	borde1->SetStacks(30);
	borde1->SetPosition(Vector3D(-1.5, 0.0, -75.0));
	borde1->SetRotation(Vector3D(0, 0, 0));
	borde1->SetColor(Color(0.1, 0.1, 0.1));

	Cylinder* borde2 = new Cylinder();
	borde2->SetRadioB(0.4);
	borde2->SetRadioPS(0.4);
	borde2->SetHeight(200);
	borde2->SetSlices(30);
	borde2->SetStacks(30);
	borde2->SetPosition(Vector3D(17.5, 0.0, -75.0));
	borde2->SetRotation(Vector3D(0, 0, 0));
	borde2->SetColor(Color(0.1, 0.1, 0.1));

	sceneL1->AddGameObject(borde1);
	sceneL1->AddGameObject(borde2);


	lifeToGenerate = new Vidas();
	ammuToGenerate = new Munición();
	obsToGenerate = new Obstáculo();

	lifeToGenerate->setPlayer(player);
	loader->setEscala(2.0);
	loader->LoadModel("3dModels\\cora.obj");
	lifeToGenerate->setModel(loader->getModel());
	loader->Clear();

	ammuToGenerate->setPlayer(player);
	loader->setEscala(1.0);
	loader->LoadModel("3dModels\\cajita.obj");
	ammuToGenerate->setModel(loader->getModel());
	loader->Clear();

	obsToGenerate->setPlayer(player);
	loader->setEscala(1.0);
	loader->LoadModel("3dModels\\roca.obj");
	obsToGenerate->setModel(loader->getModel());
	loader->Clear();

	sceneL1->AddGameObject(lifeToGenerate);
	sceneL1->AddGameObject(ammuToGenerate);
	sceneL1->AddGameObject(obsToGenerate);

}

void Game::Render() 
{
	this->activeScene->Render();
}

void Game::Update() 
{
	milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

	if (player->GetLife() == 0)
	{
		this->activeScene = sceneFin;
	}

	if ((currentTime.count() - this->initialMilliseconds.count()) - this->lastUpdateTime > UPDATE_PERIOD)
	{
		this->activeScene->Update(TIME_INCREMENT);
		this->lastUpdateTime = currentTime.count() - this->initialMilliseconds.count();
	}
	if (activeScene == sceneL1) {
		if (segundos > 500) {
			ControlFlujo();
			ControlNivel();
		}
		segundos++;
	}
}