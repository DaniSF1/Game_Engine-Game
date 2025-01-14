#pragma once
#include "Colisionables.h"

class Munici�n : public Colisionables
{
private:

	vector<Model*> listaMuniciones;

public:

	Munici�n() : listaMuniciones(), Colisionables() {}

	Model* GenerateMun();
	void Update();
};

