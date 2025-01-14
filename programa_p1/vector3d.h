#pragma once

#include <iostream>
using namespace std;

template <class S> class Vector3Dx;

typedef Vector3Dx<float> Vector3D;

typedef Vector3Dx<float>  Vector3Df;
typedef Vector3Dx<double> Vector3Dd;
typedef Vector3Dx<int>    Vector3Di;

template<class S> class Vector3Dx {
private:
    S x, y, z;
public:
    Vector3Dx() :x(0), y(0), z(0) {}

    Vector3Dx(S dx, S dy, S dz) : x(dx), y(dy), z(dz){}

    // Getters y Setters
    inline S getX() { return x; }
    inline S getY() { return y; }
    inline S getZ() { return z; }
    inline void setX(S d) { x = d; }
    inline void setY(S d) { y = d; }
    inline void setZ(S d) { z = d; }

    Vector3Dx<S> operator+(Vector3Dx<S> v);
    Vector3Dx<S> operator-(Vector3Dx<S> v);
    Vector3Dx<S> operator*(S s);
    Vector3Dx<S> operator/(S s);
    bool operator==(Vector3Dx<S> v);
    S operator*(Vector3Dx<S> v);
};

template<class S>
inline Vector3Dx<S> Vector3Dx<S>::operator+(Vector3Dx<S> v)
{
    return Vector3Dx<S>(this->getX() + v.getX(), this->getY() + v.getY(), this->getZ() + v.getZ());
}

template<class S>
inline Vector3Dx<S> Vector3Dx<S>::operator-(Vector3Dx<S> v)
{
    return Vector3Dx<S>(this->getX() - v.getX(), this->getY() - v.getY(), this->getZ() - v.getZ());
}

template<class S>
inline Vector3Dx<S> Vector3Dx<S>::operator*(S s)
{
    return Vector3Dx<S>(this->getX() * s, this->getY() * s, this->getZ() * s);
}

template<class S>
inline Vector3Dx<S> Vector3Dx<S>::operator/(S s)
{
    return Vector3Dx<S>(this->getX() / s, this->getY() / s, this->getZ() / s);
}

template<class S>
inline bool Vector3Dx<S>::operator==(Vector3Dx<S> v)
{
    if (this->getX() == v.getX() && this->getY() == v.getY() && this->getZ() == v.getZ()) {
        return true;
    }
    else return false;
}

template<class S>
inline S Vector3Dx<S>::operator*(Vector3Dx<S> v)
{
    return S(this->getX() * v.getX() + this->getY() * v.getY() + this->getZ() * v.getZ());
}