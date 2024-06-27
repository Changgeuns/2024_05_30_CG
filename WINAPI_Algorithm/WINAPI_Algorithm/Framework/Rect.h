#pragma once
#define GREEN_COLOR	 0
#define RED_COLOR	 1
#define SKYCOLOR_COLOR 2

using ColorNum = int;
class RectCollider : public enable_shared_from_this<RectCollider>
{
public:
	RectCollider(Vector2 center, Vector2 halfSize);
	~RectCollider();

	void Update();
	void Render(HDC hdc);

	bool IsCollision(Vector2 point);
	bool IsCollision(shared_ptr<class CircleCollider> other);
	bool IsCollision(shared_ptr<class RectCollider> other);

	float Left() { return _center._x - _halfSize._x; }
	float Right() { return _center._x + _halfSize._x; }
	float Top() { return _center._y - _halfSize._y; }
	float Bottom() { return _center._y + _halfSize._y; }

	void SetGreen() { SetColor(GREEN_COLOR); }
	void SetRed() { SetColor(RED_COLOR); }
	void SetSktBlue() { SetColor(SKYCOLOR_COLOR); }
public:
	void SetColor(ColorNum index);

	vector<HPEN> _pens;
	HPEN _curPen;

	Vector2 _center;
	Vector2 _halfSize;
private:
};

