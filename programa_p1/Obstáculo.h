#pragma once
#include "Colisionables.h"
class Obst�culo : public Colisionables
{
private:

	vector<Model*> listaObstaculos;

public:

	Obst�culo() : listaObstaculos(), Colisionables() {}

	Model* GenerateObs();
	void Update();
};

