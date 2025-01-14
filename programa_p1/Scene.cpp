#include "Scene.h"

void Scene::checkBoundary()
{
    for (Solid* i : gameObjects) {

        if (i->GetCoordinateX() > boundary.getX() || i->GetCoordinateX() < 0) {
            i->SetSpeedX(i->GetSpeedX() * 0);
        }
        if (i->GetCoordinateY() > boundary.getY() || i->GetCoordinateY() < 0) {
            i->SetSpeedY(i->GetSpeedY() * 0);
        }
    }
}

void Scene::AddGameObject(Solid* object)
{
	this->gameObjects.push_back(object);
}

void Scene::Borrado(Solid* objectoABorrar)
{
	vector<Solid*> aux = gameObjects;
	for (int i = 0; i < aux.size(); i++)
	{
		if (aux[i] == objectoABorrar)
		{
			remove(aux[i]);
			aux.erase(aux.begin() + i);
			gameObjects = aux;
			aux.clear();
		}
	}
}

void Scene::remove(Solid* ps)
{
	std::remove(gameObjects.begin(), gameObjects.end(), ps);
	delete ps;
}

void Scene::Render()
{
	for (Solid* i : gameObjects) {
		i->Render();
	}
}

void Scene::Update(double t)
{
	for (Solid* i : gameObjects) {
		i->Update();
		if (i->GetCoordinateZ() > 20 || i->GetCoordinateZ() < -80) {
			Borrado(i);
		}
	}
	checkBoundary();
}
