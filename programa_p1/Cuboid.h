#pragma once
#include <GL/glut.h>
#include "Solid.h"

class Cuboid : public Solid
{
private:
	float length, height, width;

public:
	Cuboid() : length(), height(), width(), Solid() {}

	Cuboid(float dl, float dh, float dw,
		Vector3D posicion,
		Vector3D orientacion,
		Color color,
		Vector3D s_orient,
		Vector3D s_pos) : length(dl), height(dh), width(dw), Solid (posicion, orientacion, color, s_orient, s_pos) {}

	inline float GetLength() const { return this->length; }
	inline float GetHeight() const { return this->height; }
	inline float GetWidth() const { return this->width; }

	inline void SetLenght(const float& lenghtToSet) { this->length = lenghtToSet; }
	inline void SetHeight(const float& heightToSet) { this->height = heightToSet; }
	inline void SetWidth(const float& widthToSet) { this->width = widthToSet; }


	void Render();
	void Update();
};

