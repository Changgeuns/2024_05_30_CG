#include "pch.h"
#include "PaintScene.h"

PaintScene::PaintScene()
{
    _rect = make_shared<RectCollider>(Vector2(0.0f, 0.0f), Vector2(50.0f, 50.0f));
    _circle = make_shared<CircleCollider>(Vector2(300.0f, 300.0f), 50);
    //_line = make_shared<Line>(Vector2(100.0f, 100.0f), Vector2(200.0f, 200.0f));

    /*_brushes.push_back(CreateSolidBrush(PANTON));
    _brushes.push_back(CreateSolidBrush(SKYCOLOR));

    _pens.push_back(CreatePen(PS_SOLID, 3, PANTON));
    _pens.push_back(CreatePen(PS_SOLID, 3, SKYCOLOR));*/
}

PaintScene::~PaintScene()
{
    for (auto brush : _brushes)
        DeleteObject(brush);
    for (auto pen : _pens)
        DeleteObject(pen);
}

void PaintScene::Update()
{
    _rect->_center = _rect->_center + Vector2(0.5f, 0.5f);


    _circle->_center = LERP(_circle->_center, mousePos, 0.1f);



    _rect->Update();
    _circle->Updete();

}

void PaintScene::Render(HDC hdc)
{ 
    // 사각형그리기
    _rect->Render(hdc);


    // 원 그리기
    _circle->Render(hdc);

}
