#pragma once
#include "Colisionables.h"
class Obstáculo : public Colisionables
{
private:

	vector<Model*> listaObstaculos;

public:

	Obstáculo() : listaObstaculos(), Colisionables() {}

	Model* GenerateObs();
	void Update();
};

