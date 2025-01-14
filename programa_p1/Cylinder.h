#pragma once
#include <GL/glut.h>
#include "Solid.h"

class Cylinder: public Solid
{
private:

	float radio_b, radio_ps, altura;
	int slices, stacks;

public:
	Cylinder() : radio_b(), radio_ps(), altura(), slices(), stacks(), Solid() {}
	Cylinder(float rb, float rps, float a, int sl, int st,
		Vector3D posicion,
		Vector3D orientacion,
		Color color,
		Vector3D s_orient,
		Vector3D s_pos) : radio_b(rb), radio_ps(rps), altura(a), slices(sl), stacks(st), Solid(posicion, orientacion, color, s_orient, s_pos) {}

	inline float GetRadioB() const { return this->radio_b; }
	inline float GetRadioPS() const { return this->radio_ps; }
	inline float GetHeight() const { return this->altura; }
	inline int GetSlices() const { return this->slices; }
	inline int GetStacks() const { return this->stacks; }

	inline void SetRadioB(const float& radio_bToSet) { this->radio_b = radio_bToSet; }
	inline void SetRadioPS(const float& radio_psToSet) { this->radio_ps = radio_psToSet; }
	inline void SetHeight(const float& heightToSet) { this->altura = heightToSet; }
	inline void SetSlices(const int& slicesToSet) { this->slices = slicesToSet; }
	inline void SetStacks(const int& stacksToSet) { this->stacks = stacksToSet; }

	void Render();
	void Update();
};

