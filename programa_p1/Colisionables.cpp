#include "Colisionables.h"

bool Colisionables::detectaColisiones(Jugador* p1, Model* sp)
{
	if ((this->player->GetCoordinateX() > (sp->GetCoordinateX() + 2) || this->player->GetCoordinateX() < (sp->GetCoordinateX() - 2)) ||
		(this->player->GetCoordinateY() > (sp->GetCoordinateY() + 2) || this->player->GetCoordinateY() < (sp->GetCoordinateY() - 2)) ||
		(this->player->GetCoordinateZ() > (sp->GetCoordinateZ() + 2) || this->player->GetCoordinateZ() < (sp->GetCoordinateZ() - 1)))
	{
		return false;
	}
	else return true;
}

void Colisionables::Render()
{
}

void Colisionables::Update()
{
}
