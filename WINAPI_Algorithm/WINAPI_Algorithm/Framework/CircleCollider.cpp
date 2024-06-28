#include "pch.h"
#include "CircleCollider.h"



CircleCollider::CircleCollider(Vector2 center, float radius)
	:_center(center), _radius(radius)
{
	_pens.push_back(CreatePen(PS_SOLID, 3, GREEN));
	_pens.push_back(CreatePen(PS_SOLID, 3, RED));
	_pens.push_back(CreatePen(PS_SOLID, 3, BLUE));

	SetColor(GREEN_COLOR);
}

CircleCollider::~CircleCollider()
{
	for(auto pen : _pens)
		DeleteObject(pen);
}

void CircleCollider::Updete()
{
}

void CircleCollider::Render(HDC hdc)
{
	SelectObject(hdc, _curPen);

	float left = _center._x - _radius;
	float right = _center._x + _radius;
	float top = _center._y - _radius;
	float bottom = _center._y + _radius;

	Ellipse(hdc, left, top, right, bottom);
}

bool CircleCollider::IsCollision(Vector2 point)
{
	float distance = _center.Distance(point);


	return distance < _radius;
}

bool CircleCollider::IsCollision(shared_ptr<CircleCollider> other)
{
	float distance = _center.Distance(other->_center);

	return distance < _radius + other->_radius;
}

bool CircleCollider::IsCollision(shared_ptr<RectCollider> other)
{
	// 과제
	// AABB(회전하지 않는다는 조건), OBB(회전이 가능하다)

	/*float left = other->Left() - _radius;
	float right = other->Right() + _radius;
	float top = other->Top() - _radius;
	float bottom = other->Bottom() + _radius;

	if (_center._x > left && _center._x < right && 
		_center._y > top && _center._y < bottom)
	{
		return true;
	}*/

	Vector2 circleCenter = _center;
	float radius = _radius;

	Vector2 rectCenter = other->_center;
	Vector2 rectHalfSize = other->_halfSize;
	// 위아래충돌 체크
	if (circleCenter._x < other->Right() && circleCenter._x > other->Left())
	{
		Vector2 newHalfSize = Vector2(rectHalfSize._x, rectHalfSize._y + radius);
		RectCollider newRect = RectCollider(other->_center, newHalfSize);

		if (newRect.IsCollision(circleCenter))
			return true;
	}
	// 좌우 충돌 체크
	else if (circleCenter._y < other->Bottom() && circleCenter._y > other->Top())
	{
		Vector2 newHalfSize = Vector2(rectHalfSize._x + radius, rectHalfSize._y);
		RectCollider newRect = RectCollider(other->_center, newHalfSize);

		if (newRect.IsCollision(circleCenter))
			return true;
	}
	//
	else 
	{
		bool check1 = IsCollision(Vector2(other->Left(), other->Top()));
		bool check2 = IsCollision(Vector2(other->Left(), other->Bottom()));
		bool check3 = IsCollision(Vector2(other->Right(), other->Top()));
		bool check4 = IsCollision(Vector2(other->Right(), other->Bottom()));

		return check1 || check2 || check3 || check4;
	}

	return false;
}

void CircleCollider::SetColor(ColorNum index)
{
	_curPen = _pens[index];
}
