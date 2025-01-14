#pragma once
class Color
{
private:
	float red;
	float green;
	float blue;

public:
	//Constructor
	Color() : red(0), green(0), blue(0) {}
	Color(float dr, float dg, float db): red(dr), green (dg), blue (db) {}

	//Getters y Setters
	inline float getRed() { return red; }
	inline float getGreen() { return green; }
	inline float getBlue() { return blue; }
	inline void setRed(float a) 
	{ 
		if (a <= 1 && a >= 0) {
			this->red = a;
		}
		else {
			this->red = 1.0;
		}
	}
	inline void setGreen(float a) 
	{
		if (a <= 1 && a >= 0) {
			this->green = a;
		}
		else {
			this->green = 1.0;
		}
	}
	inline void setBlue(float a) 
	{
		if (a <= 1 && a >= 0) {
			this->blue = a;
		}
		else {
			this->blue = 1.0;
		}
	}
};

