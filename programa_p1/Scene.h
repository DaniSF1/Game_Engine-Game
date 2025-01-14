#pragma once
#include "Cube.h"
#include "Cuboid.h"
#include "Cylinder.h"
#include "Sphere.h"
#include "Teapot.h"
#include "Torus.h"
#include "Solid.h"
#include "Camera.h"
#include "vector3d.h"
#include "Jugador.h"
#include <vector>
class Scene
{
private:

	Vector3D boundary;
	vector<Solid*> gameObjects;

	void checkBoundary();

public:

	Scene() : boundary(16, 10, 8), gameObjects() {}

	inline float GetBoundaryX() { return this->boundary.getX(); }
	inline float GetBoundaryY() { return this->boundary.getY(); }
	inline float GetBoundaryZ() { return this->boundary.getZ(); }
	inline Vector3D GetBoundary() { return this->boundary; }

	inline void SetBoundaryX(const float& boundaryXToSet) { this->boundary.setX(boundaryXToSet); }
	inline void SetBoundaryY(const float& boundaryYToSet) { this->boundary.setY(boundaryYToSet); }
	inline void SetBoundaryZ(const float& boundaryZToSet) { this->boundary.setZ(boundaryZToSet); }
	inline void SetBoundary(Vector3D boundaryToSet) {
		this->boundary.setX(boundaryToSet.getX());
		this->boundary.setY(boundaryToSet.getY());
		this->boundary.setZ(boundaryToSet.getZ());
	}

	void AddGameObject(Solid* object);
	void Borrado(Solid* objectoABorrar);
	void remove(Solid* ps);
	void Render();
	void Update(double t);
};

