#include "pch.h"
#include "PaintScene.h"

PaintScene::PaintScene()
{
    _rect = make_shared<Rect>(Vector2(0.0f, 0.0f), Vector2(50.0f, 50.0f));
    _circle = make_shared<Circle>(Vector2(300.0f, 300.0f), 50);
}

PaintScene::~PaintScene()
{
}

void PaintScene::Update()
{
    _rect->_center = _rect->_center + Vector2(0.5f, 0.5f);

    _rect->Update();

    _circle->_center = _circle->_center + Vector2(0.5f, 0.5f);

    _circle->Updete();
}

void PaintScene::Render(HDC hdc)
{
    // �� ������ : red
    HBRUSH redBrush = CreateSolidBrush(RGB(255, 0, 0));
    SelectObject(hdc, redBrush);

    _rect->Render(hdc);

    // �� ������ : blue
    HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));
    SelectObject(hdc, blueBrush);

    // �� �׸���
    //Ellipse(hdc, 200, 200, 300, 300);
    _circle->Render(hdc);

    // �� ���� ����
    HPEN greenPen = CreatePen(PS_SOLID, 3, RGB(0, 255, 0));
    SelectObject(hdc, greenPen);

    // �� �׸���
    MoveToEx(hdc, 100, 100, nullptr);
    LineTo(hdc, 200, 200);
}
