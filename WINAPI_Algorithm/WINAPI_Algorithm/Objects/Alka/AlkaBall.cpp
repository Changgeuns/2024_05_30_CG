#include "pch.h"
#include "AlkaBall.h"

AlkaBall::AlkaBall()
{
	_ball = make_shared<CircleCollider>(CENTER, 10);
}

AlkaBall::AlkaBall(Vector2 pos)
{
	_ball = make_shared<CircleCollider>(pos, 10);
}

AlkaBall::~AlkaBall()
{
}

void AlkaBall::Update()
{
	if (_isActive == false) return;

	OutControll();

	_ball->_center -= _direction * _speed;
	_ball->Update();
	
}

void AlkaBall::Render(HDC hdc)
{

	_ball->Render(hdc);
}

void AlkaBall::FirstBallShot(Vector2 startPos, Vector2 direction)
{
	_isActive = true;
	_ball->_center = startPos;
	_direction = direction;
	_direction.Normalize();
	_downVector = Vector2();
}

void AlkaBall::OutControll()
{
	Vector2 center = _ball->_center;
	if (center._x > WIN_WIDTH || center._x < 0)
	{
		_direction._x *= -1.0f;
	}
	if (center._y > WIN_HEIGHT || center._y < 0)
	{
		_direction._y *= -1.0f;
	}
}

void AlkaBall::RectControll(shared_ptr<Collider> rect)
{
    
}


