#include "pch.h"
#include "RectCollider.h"


RectCollider::RectCollider(Vector2 center, Vector2 halfSize)
	:_center(center), _halfSize(halfSize)
{
	_pens.push_back(CreatePen(PS_SOLID, 3, GREEN));
	_pens.push_back(CreatePen(PS_SOLID, 3, RED));
	_pens.push_back(CreatePen(PS_SOLID, 3, BLACK));

	SetColor(GREEN_COLOR);
}

RectCollider::~RectCollider()
{
	for (auto pen : _pens)
		DeleteObject(pen);
}

void RectCollider::Update()
{
}

void RectCollider::Render(HDC hdc)
{
	SelectObject(hdc, _curPen);

	int left = _center._x - _halfSize._x;
	int right = _center._x + _halfSize._x;
	int top = _center._y - _halfSize._y;
	int bottom = _center._y + _halfSize._y;

	Rectangle(hdc, left, top, right, bottom);
}

bool RectCollider::IsCollision(Vector2 point)
{
	// 포인트.x가 left, right 사이에있냐>
	if (point._x < Right() && point._x > Left())
	{
		if (point._y < Bottom() && point._y > Top())
			return true;
	}

	return false;
}

bool RectCollider::IsCollision(shared_ptr<class CircleCollider> other)
{
	

	return other->IsCollision(shared_from_this());

}

bool RectCollider::IsCollision(shared_ptr<RectCollider> other)
{
	if (other->Bottom() > Top() && other->Top() < Bottom())
	{
		if (other->Left() < Right() && other->Right() > Left())
		{
			return true;
		}
	}

	return false;


}



void RectCollider::SetColor(ColorNum index)
{
	_curPen = _pens[index];
}
