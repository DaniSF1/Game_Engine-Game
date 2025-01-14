#include "ModelLoader.h"
#include <string>
#include <sstream>
#include <fstream>

void ModelLoader::calcBoundaries(Vector3D vectorPoint)
{
    this->maxX = fmax(this->maxX, vectorPoint.getX());
    this->maxY = fmax(this->maxY, vectorPoint.getY());
    this->maxZ = fmax(this->maxZ, vectorPoint.getZ());

    this->minX = fmin(this->minX, vectorPoint.getX());
    this->minY = fmin(this->minY, vectorPoint.getY());
    this->minZ = fmin(this->minZ, vectorPoint.getZ());
}

Triangle ModelLoader::center(Triangle triangle)
{
    Vector3D modelCenter(this->minX + this->getWidth() / 2.0,
        this->minY + this->getHeight() / 2.0,
        this->minZ + this->getLength() / 2.0);
    Triangle centeredTriangle(
        triangle.getVert1() - modelCenter,
        triangle.getVert2() - modelCenter,
        triangle.getVert3() - modelCenter,
        triangle.getNorm1(),
        triangle.getNorm2(),
        triangle.getNorm3());
    return centeredTriangle;
}

Vector3D ModelLoader::parseObjLineToVector3D(const string& line)
{
    string typeOfPoint;
    float xCoordinate, yCoordinate, zCoordinate;
    istringstream stringStream(line);
    stringStream >> typeOfPoint >> xCoordinate >> yCoordinate >> zCoordinate;
    Vector3D vectorPoint(xCoordinate, yCoordinate, zCoordinate);
    return vectorPoint * this->getEscala();
}

Triangle ModelLoader::parseObjTriangle(const string& line)
{
    char c;
    int idxVertex0, idxVertex1, idxVertex2;
    int idxNormal0, idxNormal1, idxNormal2;

    istringstream stringStream(line);
    stringStream >> c;
    stringStream >> idxVertex0 >> c >> c >> idxNormal0;
    stringStream >> idxVertex1 >> c >> c >> idxNormal1;
    stringStream >> idxVertex2 >> c >> c >> idxNormal2;

    Vector3D vertex0 = this->vert[idxVertex0 - 1];
    Vector3D vertex1 = this->vert[idxVertex1 - 1];
    Vector3D vertex2 = this->vert[idxVertex2 - 1];
    Vector3D normal = this->norm[idxNormal0 - 1];

    Triangle parsedTriangle(vertex0, vertex1, vertex2, normal, normal, normal);
    return parsedTriangle;
}

void ModelLoader::LoadModel(const string& filePath)
{
    try
    {
        ifstream objFile(filePath);
        if (objFile.is_open())
        {
            string line;
            int count = 0;
            while (getline(objFile, line))
            {
                if (line[0] == 'v' && line[1] == 'n')
                {
                    Vector3D normal = this->parseObjLineToVector3D(line);
                    this->norm.push_back(normal);
                }
                else if (line[0] == 'v')
                {
                    Vector3D vertex = this->parseObjLineToVector3D(line);
                    this->calcBoundaries(vertex);
                    this->vert.push_back(vertex);
                }
                else if (line[0] == 'f')
                {
                    Triangle triangle = this->parseObjTriangle(line);
                    this->model.addTriangle(this->center(triangle));
                }
            }
            objFile.close();
        }
        else
        {
            cout << "No se ha podido abrir el archivo: " << filePath << endl;
        }
    }
    catch (exception& ex)
    {
        cout << "Excepción al procesar al archivo: " << filePath << endl;
        cout << ex.what() << endl;
    }
}

void ModelLoader::Clear()
{
    vert.clear();
    norm.clear();
    model.Clear();
}
