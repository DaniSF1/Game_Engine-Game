#include "Cube.h"

void Cube::Render() {
	glPushMatrix();
	glTranslated(this->GetCoordinateX(), this->GetCoordinateY(), this->GetCoordinateZ());
	glColor3f(this->GetRedComponent(), this->GetGreenComponent(), this->GetBlueComponent());
	glRotatef(this->GetRotationX(), 1.0, 0.0, 0.0);
	glRotatef(this->GetRotationY(), 0.0, 1.0, 0.0);
	glRotatef(this->GetRotationZ(), 0.0, 0.0, 1.0);
	glutSolidCube(this->GetSize());
	glPopMatrix();
}

void Cube::Update()
{
	this->SetRotation(this->GetRotation() + this->GetOrientationSpeed());
	this->SetPosition(this->GetPosition() + this->GetSpeed());
}
