#pragma once
#include <GL/glut.h>
#include "vector3d.h"
#include "Color.h"

class Solid
{
private:
	Vector3D v_pos;
	Vector3D v_ori;
	Vector3D orientationSpeed;
	Vector3D speed;

	Color v_col;

public:

	Solid() : v_pos(), v_col(), v_ori(), orientationSpeed(), speed() {}

	Solid(Vector3D posicion) : v_pos(posicion), v_col(), v_ori(), orientationSpeed(), speed() {}

	Solid(Vector3D posicion,
		Vector3D orientacion,
		Color color, 
		Vector3D orientation_speed,
		Vector3D velocidad) : v_pos(posicion), v_ori(orientacion), v_col(color), orientationSpeed(orientation_speed), speed(velocidad) {}

	inline float GetCoordinateX() { return this->v_pos.getX(); }
	inline float GetCoordinateY() { return this->v_pos.getY(); }
	inline float GetCoordinateZ() { return this->v_pos.getZ(); }
	inline float GetRedComponent() { return this->v_col.getRed(); }
	inline float GetGreenComponent() { return this->v_col.getGreen(); }
	inline float GetBlueComponent() { return this->v_col.getBlue(); }
	inline float GetRotationX() { return this->v_ori.getX(); }
	inline float GetRotationY() { return this->v_ori.getY(); }
	inline float GetRotationZ() { return this->v_ori.getZ(); }
	inline float GetOrientationSX() { return this->orientationSpeed.getX(); }
	inline float GetOrientationSY() { return this->orientationSpeed.getY(); }
	inline float GetOrientationSZ() { return this->orientationSpeed.getZ(); }
	inline float GetSpeedX() { return this->speed.getX(); }
	inline float GetSpeedY() { return this->speed.getY(); }
	inline float GetSpeedZ() { return this->speed.getZ(); }
	inline Vector3D GetRotation() { return this->v_ori; }
	inline Vector3D GetOrientationSpeed() { return this->orientationSpeed; }
	inline Vector3D GetSpeed() { return this->speed; }
	inline Vector3D GetPosition() { return this->v_pos; }


	inline void SetCoordinateX(const float& coordinateXToSet) { this->v_pos.setX(coordinateXToSet); }
	inline void SetCoordinateY(const float& coordinateYToSet) { this->v_pos.setY(coordinateYToSet); }
	inline void SetCoordinateZ(const float& coordinateZToSet) { this->v_pos.setZ(coordinateZToSet); }
	inline void SetRedComponent(const float& redComponentToSet) { this->v_col.setRed(redComponentToSet); }
	inline void SetBlueComponent(const float& blueComponentToSet) { this->v_col.setBlue(blueComponentToSet); }
	inline void SetGreenComponent(const float& greenComponentToSet) { this->v_col.setGreen(greenComponentToSet); }
	inline void SetRotationX(const float& rotationXToSet) { this->v_ori.setX(rotationXToSet); }
	inline void SetRotationY(const float& rotationYToSet) { this->v_ori.setY(rotationYToSet); }
	inline void SetRotationZ(const float& rotationZToSet) { this->v_ori.setZ(rotationZToSet); }
	inline void SetOrientationSX(const float& orientationSXToSet) { this->orientationSpeed.setX(orientationSXToSet); }
	inline void SetOrientationSY(const float& orientationSYToSet) { this->orientationSpeed.setY(orientationSYToSet); }
	inline void SetOrientationSZ(const float& orientationSZToSet) { this->orientationSpeed.setZ(orientationSZToSet); }
	inline void SetSpeedX(const float& speedXToSet) { this->speed.setX(speedXToSet); }
	inline void SetSpeedY(const float& speedYToSet) { this->speed.setY(speedYToSet); }
	inline void SetSpeedZ(const float& speedZToSet) { this->speed.setZ(speedZToSet); }

	inline void SetSpeed(Vector3D speedToSet) { this->speed = speedToSet; }

	inline void SetOrientationSpeed(Vector3D or_speedToSet) { this->orientationSpeed = or_speedToSet; }

	void SetPosition(Vector3D positionToSet) { this->v_pos = positionToSet; }

	void SetRotation(Vector3D rotationToSet) { this->v_ori = rotationToSet; }

	void SetColor(Color colorToSet) { this->v_col = colorToSet; }

	virtual void Render() = 0;
	virtual void Update() = 0;
};