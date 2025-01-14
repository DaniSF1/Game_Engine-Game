#pragma once
#include "Solid.h"


class Triangle : public Solid
{
private:
	Vector3D vert1, vert2, vert3;
	Vector3D norm1, norm2, norm3;

	Color col1, col2, col3;

public:
	Triangle() : vert1(), vert2(), vert3(), norm1(), norm2(), norm3(), col1(), col2(), col3() {}

	Triangle(Vector3D v1, Vector3D v2, Vector3D v3,
		Vector3D n1, Vector3D n2, Vector3D n3) : vert1(v1), vert2(v2), vert3(v3), norm1(n1), norm2(n2), norm3(n3),
		col1(Color(0.2, 0.3, 0.4)), col2(Color(0.2, 0.3, 0.4)), col3(Color(0.2, 0.3, 0.4)) {}

	Triangle(Vector3D v1, Vector3D v2, Vector3D v3, 
		Vector3D n1, Vector3D n2, Vector3D n3,
		Color c1, Color c2, Color c3) : vert1(v1), vert2(v2), vert3(v3), norm1(n1), norm2(n2), norm3(n3), col1(c1), col2(c2), col3(c3) {}

	inline Vector3D& getVert1() { return this->vert1; }
	inline Vector3D& getVert2() { return this->vert2; }
	inline Vector3D& getVert3() { return this->vert3; }

	inline Vector3D& getNorm1() { return this->norm1; }
	inline Vector3D& getNorm2() { return this->norm2; }
	inline Vector3D& getNorm3() { return this->norm3; }

	inline Color& getCol1() { return this->col1; }
	inline Color& getCol2() { return this->col2; }
	inline Color& getCol3() { return this->col3; }

	inline void setVert1(const Vector3D& vert1ToSet) { this->vert1 = vert1ToSet; }
	inline void setVert2(const Vector3D& vert2ToSet) { this->vert2 = vert2ToSet; }
	inline void setVert3(const Vector3D& vert3ToSet) { this->vert3 = vert3ToSet; }

	inline void setNorm1(const Vector3D& norm1ToSet) { this->norm1 = norm1ToSet; }
	inline void setNorm2(const Vector3D& norm2ToSet) { this->norm2 = norm2ToSet; }
	inline void setNorm3(const Vector3D& norm3ToSet) { this->norm3 = norm3ToSet; }

	inline void setCol1(const Color& col1ToSet) { this->col1 = col1ToSet; }
	inline void setCol2(const Color& col2ToSet) { this->col2 = col2ToSet; }
	inline void setCol3(const Color& col3ToSet) { this->col3 = col3ToSet; }

	void Render();
	void Update();
};

