#include "Obstáculo.h"

Model* Obstáculo::GenerateObs()
{
	int h = rand() % 16;
	int y = rand() % 11;

	Model* o = new Model();
	*o = this->GetModel();
	o->SetPosition(Vector3D(h, y, -40));
	o->SetSpeedZ(0.1);

	listaObstaculos.push_back(o);

	return o;
}

void Obstáculo::Update()
{
	for (Model* i : listaObstaculos) {
		if (this->detectaColisiones(this->GetPlayer(), i))
		{
			this->GetPlayer()->SetLife(this->GetPlayer()->GetLife() - 1);
			i->SetCoordinateZ(21);
		}
		if (i->GetCoordinateZ() > 20 || i->GetCoordinateZ() < -80) {
			listaObstaculos.erase(listaObstaculos.begin());
		}
	}
}
