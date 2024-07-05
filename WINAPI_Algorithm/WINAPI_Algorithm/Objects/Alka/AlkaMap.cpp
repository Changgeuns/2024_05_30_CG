#include "pch.h"
#include "AlkaMap.h"

#include "Objects/Alka/AlkaRect.h"
#include "Objects/Alka/AlkaBall.h"

AlkaMap::AlkaMap()
{
	Vector2 offSet = Vector2(100, 100);

	_rect.reserve(MAXCOUNT_Y);

	for (int i = 0; i < MAXCOUNT_Y; i++)
	{
		vector<shared_ptr<AlkaRect>> rect_X;
		rect_X.reserve(MAXCOUNT_X);

		for (int j = 0; j < MAXCOUNT_X; j++)
		{
			Vector2 rectOffset = offSet + Vector2(120.0f * j, 60.0f * i);

			shared_ptr<AlkaRect> rect = make_shared<AlkaRect>();
			rect->SetPosition(rectOffset);
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

void AlkaMap::IsCollision(shared_ptr<class AlkaBall> ball)
{
	for (auto rect_X : _rect)
	{
		for (auto rect : rect_X)
		{
			Vector2 dir = ball->GetDirection();
			if (rect->IsCollision(ball->GetCircleCollider()) == false) continue;

			dir._y *= -1.0f;
			ball->SetDirection(dir);
			
			rect->DeedMove();
		}
	}
}

void AlkaMap::IsCollisionUpDwon(shared_ptr<class AlkaBall> ball)
{
	
}

void AlkaMap::IsCollisionRightLeft(shared_ptr<class AlkaBall> ball)
{
	
}


