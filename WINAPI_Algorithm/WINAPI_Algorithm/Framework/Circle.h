#pragma once
#define GREEN_COLOR	 0
#define RED_COLOR	 1
#define BLACK_COLOR   2

class CircleCollider
{
public:
	CircleCollider(Vector2 center, float radius);
	~CircleCollider();

	void Updete();
	void Render(HDC hdc);

	bool IsCollision(Vector2 point);
	bool IsCollision(shared_ptr<class CircleCollider> other);
	bool IsCollision(shared_ptr<RectCollider> other);

	void SetGreen() { SetColor(GREEN_COLOR); }
	void SetRed() { SetColor(RED_COLOR); }
	void SetBlack() { SetColor(BLACK_COLOR); }

public:
	void SetColor(ColorNum index);

	vector<HPEN> _pens;
	HPEN _curPen;

	Vector2 _center;
	float _radius;
private:


};

