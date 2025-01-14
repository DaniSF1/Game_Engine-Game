#include "Interfaz.h"

void Interfaz::AddTexto(Text* c)
{
	this->texto.push_back(c);
}

void Interfaz::Render()
{
	for (Text* t : texto)
	{
		t->Render();
	}
}

void Interfaz::Update()
{
	this->Clear();
	Text* vidas = new Text();
	string v = "Vidas: " + to_string(this->GetJugador()->GetLife());
	vidas->setTexto(v);
	vidas->SetPosition(Vector3D(-2.0, 10.0, 0.5));

	Text* municion = new Text();
	string m = "Municion: " + to_string(this->GetJugador()->GetAmunnition());
	municion->setTexto(m);
	municion->SetPosition(Vector3D(-2.0, 9.0, 0.5));

	Text* nivel = new Text();
	string l = "Nivel: " + to_string(this->GetJugador()->GetNivel());
	nivel->setTexto(l);
	nivel->SetPosition(Vector3D(-2.0, 8.0, 0.5));

	this->AddTexto(vidas);
	this->AddTexto(municion);
	this->AddTexto(nivel);
}

void Interfaz::Clear()
{
	this->texto.clear();
}
