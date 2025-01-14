#pragma once
#include "Solid.h"
class Camera : public Solid
{
public:
    Camera() : Solid() {}

    Camera(Vector3D posicion) : Solid(posicion){}

    void Render();
    void Update();
};

