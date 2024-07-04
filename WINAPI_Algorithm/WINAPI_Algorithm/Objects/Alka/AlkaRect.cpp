#include "pch.h"
#include "AlkaRect.h"

AlkaRect::AlkaRect()
	: RectCollider(Vector2(), Vector2(10, 20))
{
	_brushes.push_back(CreateSolidBrush(GREEN));
	_brushes.push_back(CreateSolidBrush(RED));
	_brushes.push_back(CreateSolidBrush(BLUE));

	// _pens[0] ... Green
	// _pens[1] ... Red
	_pens.push_back(CreatePen(PS_SOLID, 3, BLUE));

}

AlkaRect::~AlkaRect()
{
	for (auto brush : _brushes)
		DeleteObject(brush);
}

void AlkaRect::Update()
{
	RectCollider::Update();
}

void AlkaRect::Render(HDC hdc)
{
	SelectObject(hdc, _brushes[static_cast<int>(_type)]);
	RectCollider::Render(hdc);
}
