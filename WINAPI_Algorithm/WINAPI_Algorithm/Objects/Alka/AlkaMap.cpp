#include "pch.h"
#include "AlkaMap.h"

#include "AlkaRect.h"

AlkaMap::AlkaMap()
{
	//Vector2 offSet = Vector2(500, 200);

	_rect.reserve(MAXCOUNT_Y);

	for (int i = 0; i < MAXCOUNT_Y; i++)
	{
		vector<shared_ptr<Collider>> rect_X;
		rect_X.reserve(MAXCOUNT_X);

		for (int j = 0; j < MAXCOUNT_X; j++)
		{
			Vector2 rectOffset = Vector2(16.0f * j, 16.0f * i);

			shared_ptr<Collider> rect = make_shared<RectCollider>();
			rect_X.push_back(rect);
		}

		_rect.push_back(rect_X);
	}
}

AlkaMap::~AlkaMap()
{
}

void AlkaMap::Update()
{
	for (auto rect_X : _rect)
	{
		for (auto rect : rect_X)
		{
			rect->Update();
		}
	}
}

void AlkaMap::Render(HDC hdc)
{
	for (auto rect_X : _rect)
	{
		for (auto rect : rect_X)
		{
			rect->Render(hdc);
		}
	}
}
