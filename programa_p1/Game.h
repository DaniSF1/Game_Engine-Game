#pragma once
#include "Scene.h"
#include "ModelLoader.h"
#include "Model.h"
#include "Jugador.h"
#include "Vidas.h"
#include "Munición.h"
#include "Obstáculo.h"
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace chrono;


class Game
{
private:

	const double TIME_INCREMENT = 0.4;				//ms tiempo en el juego
	const long UPDATE_PERIOD = 10;					//ms tiempo en el mundo real

	milliseconds initialMilliseconds;
	long lastUpdateTime;

	Scene* activeScene;
	vector<Scene*> scenes;
	Jugador* player;
	int segundos = 0;

	Scene* sceneTitulo = new(nothrow) Scene();
	Scene* sceneInic = new(nothrow) Scene();
	Scene* sceneL1 = new(nothrow) Scene();
	Scene* sceneFin = new(nothrow) Scene();
	Scene* sceneGanador = new(nothrow) Scene();

	Vidas* lifeToGenerate;
	Munición* ammuToGenerate;
	Obstáculo* obsToGenerate;

public:

	Game() : activeScene(nullptr), initialMilliseconds(duration_cast<milliseconds>(system_clock::now().time_since_epoch())), lastUpdateTime(0), player(nullptr) {}

	void Init();
	void Render();
	void Update();
	void ProcessKeyPressed(unsigned char key, int px, int py);
	void ProcessMouseMovement(int x, int y);
	void ProcessMouseClick(int button, int state, int x, int y);
	void GenerarObjeto();
	void ControlFlujo();
	void ControlNivel();
	int GenerateRandom(int min, int max);
};

