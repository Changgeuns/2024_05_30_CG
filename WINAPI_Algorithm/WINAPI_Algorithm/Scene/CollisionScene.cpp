#include "pch.h"
#include "CollisionScene.h"

CollisionScene::CollisionScene()
{
	_circle1 = make_shared< CircleCollider>(Vector2(500, 500), 50);
	_moveCircle = make_shared< CircleCollider>(Vector2(0, 0), 30);

	_rect1 = make_shared<RectCollider>(Vector2(700, 300), Vector2(50, 70));
	_moveRect = make_shared<RectCollider>(Vector2(0, 0), Vector2(30, 30));
}

CollisionScene::~CollisionScene()
{
}

void CollisionScene::Update()
{
	//_moveCircle->_center = mousePos;
	_moveRect->_center = mousePos;

	_circle1->Updete();
	_circle1->Updete();
	
	_rect1->Update();
	_moveRect->Update();

	// 원 > 원 충돌
	if (_moveCircle->IsCollision(_circle1)) _moveCircle->SetRed();
	else _moveCircle->SetGreen();

	// 네모 > 네모 충돌
	if (_moveRect->IsCollision(_rect1)) _moveRect->SetRed();
	else _moveRect->SetGreen();
	
	// 원 > 마우스 충돌
	if (_circle1->IsCollision(mousePos))
	{
		_circle1->SetRed();
	}
	else
		_circle1->SetGreen();
	
	// 네모 > 마우스 충돌
	if (_rect1->IsCollision(mousePos)) _rect1->SetRed();
	else _rect1->SetGreen();

	// 원>네모 충돌
	if (_moveCircle->IsCollision(_rect1)) _moveCircle->SetBlack();
	else _moveCircle->SetGreen();

	// 네모 > 원 충돌
	if (_moveRect->IsCollision(_circle1)) _moveRect->SetSktBlue();
	else _moveCircle->SetGreen();


}

void CollisionScene::Render(HDC hdc)
{
	_circle1->Render(hdc);
	_moveCircle->Render(hdc);

	_rect1->Render(hdc);
	_moveRect->Render(hdc);
}
