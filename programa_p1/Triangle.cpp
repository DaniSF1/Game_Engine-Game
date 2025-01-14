#include "Triangle.h"

void Triangle::Render()
{
	glBegin(GL_TRIANGLES);
	//vértice 1
	glColor3f(this->col1.getRed(), this->col1.getGreen(), this->col1.getBlue());
	glNormal3f(this->norm1.getX(), this->norm1.getY(), this->norm1.getZ());
	glVertex3f(this->vert1.getX(), this->vert1.getY(), this->vert1.getZ());
	//vértice 2
	glColor3f(this->col2.getRed(), this->col2.getGreen(), this->col2.getBlue());
	glNormal3f(this->norm2.getX(), this->norm2.getY(), this->norm2.getZ());
	glVertex3f(this->vert2.getX(), this->vert2.getY(), this->vert2.getZ());
	//vértice 3
	glColor3f(this->col3.getRed(), this->col3.getGreen(), this->col3.getBlue());
	glNormal3f(this->norm3.getX(), this->norm3.getY(), this->norm3.getZ());
	glVertex3f(this->vert3.getX(), this->vert3.getY(), this->vert3.getZ());
	glEnd();

}

void Triangle::Update()
{
}
