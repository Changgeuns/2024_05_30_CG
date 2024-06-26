#pragma once
class Circle
{
public:
	Circle(Vector2 center, int radius);
	~Circle() {}

	void Updete();
	void Render(HDC hdc);


	Vector2 _center;
	int _radius;
private:


};

