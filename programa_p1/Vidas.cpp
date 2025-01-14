#include "Vidas.h"

Model* Vidas::GenerarVida()
{
	int h = rand() % 16;
	int y = rand() % 11;

	Model* v = new Model();
	*v = this->GetModel();
	v->SetPosition(Vector3D(h, y, -40));
	v->SetSpeedZ(0.1);
	v->PaintColor(Color(0.6, 0.2, 0.3));

	listaVidas.push_back(v);

	return v;
}

void Vidas::Update()
{
	for (Model* i : listaVidas) {
		if (this->detectaColisiones(this->GetPlayer(), i)) 
		{
			this->GetPlayer()->SetLife(this->GetPlayer()->GetLife() + 1);
			i->SetCoordinateZ(21);
		}
		if (i->GetCoordinateZ() > 20 || i->GetCoordinateZ() < -80) {
			listaVidas.erase(listaVidas.begin());
		}
	}
}
