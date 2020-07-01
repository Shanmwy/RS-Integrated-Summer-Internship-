#pragma once

//³ÂÞÈ×¿6.30£ºµãÀà
class MyPoint
{
public:
	MyPoint(float x, float y) :x(x), y(y) {}
	float x;
	float y;
};

class MyBoundingBox
{
public:
	MyBoundingBox(float xmin, float xmax, float ymin, float ymax) :xmin(xmin), xmax(xmax), ymin(ymin), ymax(ymax) {}
	MyBoundingBox() {}
	float xmin;
	float xmax;
	float ymin;
	float ymax;
	float Height()
	{
		return ymax - ymin;
	}
	float Width()
	{
		return xmax - xmin;
	}
};