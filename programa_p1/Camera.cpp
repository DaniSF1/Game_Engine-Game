#include "Camera.h"

void Camera::Render()
{
	glTranslatef(-1 * this->GetCoordinateX(), -1 * this->GetCoordinateY(), -1 * this->GetCoordinateZ());
	glRotatef(this->GetRotationX(), 1.0, 0.0, 0.0);
	glRotatef(this->GetRotationY(), 0.0, 1.0, 0.0);
	glRotatef(this->GetRotationZ(), 0.0, 0.0, 1.0);

}

void Camera::Update()
{
}
