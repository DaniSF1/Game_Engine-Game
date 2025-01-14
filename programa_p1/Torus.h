#pragma once
#include <GL/glut.h>
#include "Solid.h"

class Torus : public Solid
{
private:

	float radio_i, radio_e;
	int caras, anillos;

public:

	Torus() : radio_i(), radio_e(), caras(), anillos(), Solid() {}
	Torus(float dri, float dre, int c, int a,
		Vector3D posicion,
		Vector3D orientacion,
		Color color,
		Vector3D s_orient,
		Vector3D s_pos) : radio_i(dri), radio_e(dre), caras(c), anillos(a), Solid(posicion, orientacion, color, s_orient, s_pos) {}

	inline float GetRadioI() const { return this->radio_i; }
	inline float GetRadioE() const { return this->radio_e; }
	inline int GetCaras() const { return this->caras; }
	inline int GetAnillos() const { return this->anillos; }

	inline void SetRadioI(const float& radio_iToSet) { this->radio_i = radio_iToSet; }
	inline void SetRadioE(const float& radio_eToSet) { this->radio_e = radio_eToSet; }
	inline void SetCaras(const int& carasToSet) { this->caras = carasToSet; }
	inline void SetAnillos(const int& anillosToSet) { this->anillos = anillosToSet; }

	void Render();
	void Update();
};

