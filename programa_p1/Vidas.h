#pragma once
#include "Colisionables.h"

class Vidas : public Colisionables
{
private:

	vector<Model*> listaVidas;

public:
	
	Vidas() : listaVidas(), Colisionables() {}

	Model* GenerarVida();
	void Update();

};

