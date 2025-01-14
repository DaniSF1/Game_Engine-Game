#pragma once
#include "Model.h"
#include <vector>

class ModelLoader
{
private:
    float escala = 1.0;
    Model model;
    vector<Vector3D> vert;
    vector<Vector3D> norm;
    float maxX, minX, maxY, minY, maxZ, minZ;

    float getWidth() { return (maxX - minX); }
    float getHeight() { return (maxY - minY); }
    float getLength() { return (maxZ - minZ); }

    void calcBoundaries(Vector3D vectorPoint);
    Triangle center(Triangle triangle);
    Vector3D parseObjLineToVector3D(const string& line);
    Triangle parseObjTriangle(const string& line);

public:

    inline Model getModel() const { return model; }

    inline float getEscala() const { return escala; }
    inline void setEscala(const float& escalaToSet) { this->escala = escalaToSet; }

    void LoadModel(const string& filePath);
    void Clear();
};

