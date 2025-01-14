#include "Munici�n.h"

Model* Munici�n::GenerateMun()
{
	int h = rand() % 16;
	int y = rand() % 11;

	Model* m = new Model();
	*m = this->GetModel();
	m->SetPosition(Vector3D(h, y, -40));
	m->SetSpeedZ(0.1);
	m->PaintColor(Color(0.5, 0.5, 0.5));

	listaMuniciones.push_back(m);

	return m;
}

void Munici�n::Update()
{
	for (Model* i : listaMuniciones) {
		if (this->detectaColisiones(this->GetPlayer(), i))
		{
			this->GetPlayer()->SetAmunnition(this->GetPlayer()->GetAmunnition() + 5);
			i->SetCoordinateZ(21);
		}
		if (i->GetCoordinateZ() > 20 || i->GetCoordinateZ() < -80) {
			listaMuniciones.erase(listaMuniciones.begin());
		}
	}
}
