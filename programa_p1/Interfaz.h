#pragma once
#include "Solid.h"
#include "Text.h"
#include "Jugador.h"
#include <vector>

class Interfaz : public Solid
{
private:

	Jugador* jugador;
	vector<Text*> texto;

public:

	Interfaz(Jugador* p1) : jugador(p1), Solid() {}

	inline Jugador* GetJugador() { return this->jugador; }
	inline void SetJugador(Jugador* jugadorToSet) { this->jugador = jugadorToSet; }

	void AddTexto(Text* c);
	void Render();
	void Update();
	void Clear();
};

