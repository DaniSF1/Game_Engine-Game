#pragma once
#include "Solid.h"
#include "Triangle.h"
#include <vector>

class Model : public Solid
{
private:
	vector<Triangle> gameTriangles;

public:

	void addTriangle(Triangle triangle);
	void Clear();
	void PaintColor(Color color);
	void Render();
	void Update();
};

