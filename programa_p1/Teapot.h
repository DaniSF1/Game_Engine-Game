#pragma once
#include <GL/glut.h>
#include "Solid.h"


class Teapot : public Solid
{
private:

	float size;

public:
	Teapot() : size(), Solid() {}

	Teapot(float ds, 
		Vector3D posicion,
		Vector3D orientacion,
		Color color,
		Vector3D s_orient,
		Vector3D s_pos) : size(ds), Solid(posicion, orientacion, color, s_orient, s_pos) {}

	inline float GetSize() const { return this->size; }
	inline void SetSize(const float& sizeToSet) { this->size = sizeToSet; }


	void Render();
	void Update();
};

