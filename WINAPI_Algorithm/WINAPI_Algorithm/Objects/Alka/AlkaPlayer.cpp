#include "pch.h"
#include "AlkaPlayer.h"

#include "Objects/Alka/AlkaBall.h"
#include "Objects/Alka/AlkaRect.h"

AlkaPlayer::AlkaPlayer()
{
	_Bar = make_shared<RectCollider>(Vector2(650, 600), Vector2(60, 10));
	_Firstball = make_shared<AlkaBall>(Vector2(_Bar->_center._x, _Bar->_center._y - 20));
	
	_rects = make_shared<AlkaRect>();

	for (int i = 0; i < 100; i++)
	{
		shared_ptr<AlkaBall> ball = make_shared<AlkaBall>(Vector2(0,0));
		ball->SetActive(false);
		_balls.push_back(ball);
	}
}

AlkaPlayer::~AlkaPlayer()
{
}

void AlkaPlayer::Update()
{
	_Firstball->RectControll(_Bar); 
	if (!firstShot) FirstBallShot();

	Move();


	_Bar->Update();
	_Firstball->Update();
	_rects->Update();
		
	for (auto ball : _balls)
	{
		ball->Update();
	}
}

void AlkaPlayer::Render(HDC hdc)
{
	_Bar->Render(hdc);
	_Firstball->Render(hdc);
	_rects->Render(hdc);
	

	for (auto ball : _balls)
	{
		ball->Render(hdc);
	}
}

void AlkaPlayer::Move()
{
	shared_ptr<Collider> F_ball = _Firstball->GetFirstBall();
	if (GetAsyncKeyState(VK_RIGHT))
	{
		_Bar->_center._x += 3.5f;
		if (!firstShot) F_ball->_center._x += 3.5f;
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		_Bar->_center._x -= 3.5f;
		if (!firstShot) F_ball->_center._x -= 3.5f;
	}
}


void AlkaPlayer::FirstBallShot()
{
	if (GetAsyncKeyState(VK_SPACE) & 0x0001)
    {
        firstShot = true;

        Vector2 initialDirection = _Firstball->GetDirection();

        _Firstball->FirstBallShot(
            Vector2(_Bar->_center._x, _Bar->_center._y - 20),
            initialDirection);
    }
}
