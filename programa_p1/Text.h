#pragma once
#include "Solid.h"
#include <string>

class Text : public Solid
{
private:

	string texto;

public:

	Text() : texto() {}

	inline string getTexto() { return texto; }
	inline void setTexto(const string& textoToSet) { this->texto = textoToSet; }

	void Render();
	void Update();
};

