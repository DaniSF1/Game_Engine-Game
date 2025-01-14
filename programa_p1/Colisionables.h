#pragma once
#include "Solid.h"
#include "Sphere.h"
#include "Model.h"
#include "Jugador.h"
#include "Scene.h"
#include <vector>

class Colisionables : public Solid
{
private:

	Jugador* player;
	Model model;

public:

	Colisionables() : player(), model(), Solid() {}

	inline Jugador* GetPlayer() { return this->player; }
	inline Model GetModel() { return this->model; }
	inline void setPlayer(Jugador* playerToSet) { this->player = playerToSet; }
	inline void setModel(Model modelToSet) { this->model = modelToSet; }

	virtual bool detectaColisiones(Jugador* p1, Model* sp);
	void Render();
	void Update();
};

