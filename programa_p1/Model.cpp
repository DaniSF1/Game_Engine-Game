#include "Model.h"

void Model::addTriangle(Triangle triangle)
{
	this->gameTriangles.push_back(triangle);
}

void Model::Clear()
{
	this->gameTriangles.clear();
}

void Model::PaintColor(Color color)
{
	for (Triangle& triangle : this->gameTriangles) {
		triangle.setCol1(color);
		triangle.setCol2(color);
		triangle.setCol3(color);
	}
}

void Model::Render()
{
	
	glPushMatrix();
	glTranslatef(this->GetCoordinateX(), this->GetCoordinateY(), this->GetCoordinateZ());
	glColor3f(this->GetRedComponent(), this->GetGreenComponent(), this->GetBlueComponent());
	glRotatef(this->GetRotationX(), 1.0, 0.0, 0.0);
	glRotatef(this->GetRotationY(), 0.0, 1.0, 0.0);
	glRotatef(this->GetRotationZ(), 0.0, 0.0, 1.0);
	for (Triangle& t : this->gameTriangles) {
		t.Render();
	}
	glPopMatrix();

}

void Model::Update()
{
	this->SetRotation(this->GetRotation() + this->GetOrientationSpeed());
	this->SetPosition(this->GetPosition() + this->GetSpeed());
}
