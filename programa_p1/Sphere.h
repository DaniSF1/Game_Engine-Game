#pragma once
#include <GL/glut.h>
#include "Solid.h"

class Sphere : public Solid
{
private:

	float radio, slices, slacks;


public:
	Sphere() :radio(0.5), slices(20), slacks(20), Solid () {}
	Sphere(float radio, float slices, float slacks,
		Vector3D posicion,
		Vector3D orientacion,
		Color color,
		Vector3D s_orient,
		Vector3D s_pos) : radio(radio), slices(slices), slacks(slacks), Solid(posicion, orientacion, color, s_orient, s_pos) {}

	inline float GetRadio() { return this->radio; }
	inline float GetSlices() { return this->slices; }
	inline float GetSlacks() { return this->slacks; }

	inline void SetRadio(const float& radioToSet) { this->radio = radioToSet; }
	inline void SetSlices(const float& sliceToSet) { this->slices = sliceToSet; }
	inline void SetSlacks(const float& slacksToSet) { this->slacks = slacksToSet; }

	void Render();
	void Update();
};

