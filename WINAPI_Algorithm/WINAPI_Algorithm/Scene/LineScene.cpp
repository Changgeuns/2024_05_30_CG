#include "pch.h"
#include "LineScene.h"

LineScene::LineScene()
{
	_line1 = make_shared<Line>(Vector2(100, 500), Vector2(1000, 400));
	_line2 = make_shared<Line>(Vector2(100, 450), Vector2(0, 0));

	_line3 = make_shared<Line>(Vector2(100, 470), Vector2(150, 470));
}

LineScene::~LineScene()
{
}

void LineScene::Update()
{
	
	_line2->_end = mousePos;

	// 이부분 라인 1을그림자 삼아서 라인 1과 평행 하며 늘어나는
	// 라인 3를 만들어야함 길이는 라인3와 라인 1의 위에서 라인 1에 평행으로
	// 내리쬐는 태양이 있다고 가정하고 그 그림자 만큼 라인 3이 늘어나야함

	Vector2 a = (_line2->_end - _line2->_start); // A
	Vector2 b = (_line1->_end - _line1->_start); // B

	Vector2 bNormal = b.NormalVector2(); //B 의 단위벡터

	float line2Length = a.Dot(bNormal); // 그림자의 길이.. 투영됬을 때 길이

	Vector2 line3Delta = bNormal * line2Length;

	_line3->_end = _line3->_start + line3Delta;

	_line1->Update();
	_line2->Update();
	_line3->Update();
}

void LineScene::Render(HDC hdc)
{
	_line1->Render(hdc);
	_line2->Render(hdc);
	_line3->Render(hdc);
}
