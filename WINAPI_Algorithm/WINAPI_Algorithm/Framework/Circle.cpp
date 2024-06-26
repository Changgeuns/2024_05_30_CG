#include "pch.h"
#include "Circle.h"

Circle::Circle(Vector2 center, int radius)
	:_center(center), _radius(radius)
{
}

void Circle::Updete()
{
}

void Circle::Render(HDC hdc)
{
	int left = _center._x - _radius;
	int right = _center._x + _radius;
	int top = _center._y - _radius;
	int bottom = _center._y + _radius;

	Ellipse(hdc, left, top, right, bottom);
}
