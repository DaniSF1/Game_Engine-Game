#include "Torus.h"

void Torus::Render() {
	glPushMatrix();
	glTranslatef(this->GetCoordinateX(), this->GetCoordinateY(), this->GetCoordinateZ());
	glColor3f(this->GetRedComponent(), this->GetGreenComponent(), this->GetBlueComponent());
	glRotatef(this->GetRotationX(), 1.0, 0.0, 0.0);
	glRotatef(this->GetRotationY(), 0.0, 1.0, 0.0);
	glRotatef(this->GetRotationZ(), 0.0, 0.0, 1.0);
	glutSolidTorus(this->GetRadioI(), this->GetRadioE(), this->GetCaras(), this->GetAnillos());
	glPopMatrix();

}

void Torus::Update()
{
	this->SetRotation(this->GetRotation() + this->GetOrientationSpeed());
	this->SetPosition(this->GetPosition() + this->GetSpeed());
}
