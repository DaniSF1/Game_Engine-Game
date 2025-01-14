#include "Sphere.h"

void Sphere::Render() {
	glPushMatrix();
	glTranslated(this->GetCoordinateX(), this->GetCoordinateY(), this->GetCoordinateZ());
	glColor3f(this->GetRedComponent(), this->GetGreenComponent(), this->GetBlueComponent());
	glRotatef(this->GetRotationX(), 1.0, 0.0, 0.0);
	glRotatef(this->GetRotationY(), 0.0, 1.0, 0.0);
	glRotatef(this->GetRotationZ(), 0.0, 0.0, 1.0);
	glutSolidSphere(this->GetRadio(), this->GetSlices(), this->GetSlacks());
	glPopMatrix();
}

void Sphere::Update()
{
	this->SetRotation(this->GetRotation() + this->GetOrientationSpeed());
	this->SetPosition(this->GetPosition() + this->GetSpeed());
}
