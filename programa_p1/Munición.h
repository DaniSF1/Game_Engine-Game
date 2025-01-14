#pragma once
#include "Colisionables.h"

class Munición : public Colisionables
{
private:

	vector<Model*> listaMuniciones;

public:

	Munición() : listaMuniciones(), Colisionables() {}

	Model* GenerateMun();
	void Update();
};

