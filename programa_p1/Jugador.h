#pragma once
#include "Model.h"
#include "Cylinder.h"

class Jugador : public Model
{
private:

	int vida, municion, nivel;

public:

	Jugador(Model model) : vida(3), municion(0), nivel(1), Model(model) {}

	inline int GetLife() { return this->vida; }
	inline int GetAmunnition() { return this->municion; }
	inline int GetNivel() { return this->nivel; }

	inline void SetLife(const int& lifetoSet) { this->vida = lifetoSet; }
	inline void SetAmunnition(const int& bulletstoSet) { this->municion = bulletstoSet; }
	inline void SetNivel(const int& levelToSet) { this->nivel = levelToSet; }
};

