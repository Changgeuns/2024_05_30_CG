#include "pch.h"
#include "Line.h"

Line::Line(Vector2 start, Vector2 end)
	:_start(start), _end(end)
{
	_pens.push_back(CreatePen(PS_SOLID, 3, RED));
	_pens.push_back(CreatePen(PS_SOLID, 3, GREEN));

	SetGreen();
}

Line::~Line()
{
	for (auto pen : _pens)
		DeleteObject(pen);
}

void Line::Update()
{
}

void Line::Render(HDC hdc)
{
	SelectObject(hdc, _curPen);


	MoveToEx(hdc, _start._x, _start._y, nullptr);
	LineTo(hdc, _end._x, _end._y);
}

HResult Line::IsCollision(shared_ptr<Line> other)
{
    //Vector2 p1 = _start, q1 = _end;
    //Vector2 p2 = other->_start, q2 = other->_end;

    //// 도우미 함수를 직접 구현
    //auto onSegment = [](Vector2 p, Vector2 q, Vector2 r) -> bool {
    //    return q._x <= max(p._x, r._x) && q._x >= min(p._x, r._x) &&
    //        q._y <= max(p._y, r._y) && q._y >= min(p._y, r._y);
    //    };

    //auto orientation = [](Vector2 p, Vector2 q, Vector2 r) -> int {
    //    int val = (q._y - p._y) * (r._x - q._x) - (q._x - p._x) * (r._y - q._y);
    //    if (val == 0) return 0; // collinear
    //    return (val > 0) ? 1 : 2; // clock or counterclock wise
    //    };

    //// Find the four orientations needed for the general and special cases
    //int o1 = orientation(p1, q1, p2);
    //int o2 = orientation(p1, q1, q2);
    //int o3 = orientation(p2, q2, p1);
    //int o4 = orientation(p2, q2, q1);

    //// General case
    //if (o1 != o2 && o3 != o4)
    //    return true;

    //// Special Cases
    //// p1, q1 and p2 are collinear and p2 lies on segment p1q1
    //if (o1 == 0 && onSegment(p1, p2, q1)) return true;

    //// p1, q1 and q2 are collinear and q2 lies on segment p1q1
    //if (o2 == 0 && onSegment(p1, q2, q1)) return true;

    //// p2, q2 and p1 are collinear and p1 lies on segment p2q2
    //if (o3 == 0 && onSegment(p2, p1, q2)) return true;

    //// p2, q2 and q1 are collinear and q1 lies on segment p2q2
    //if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    HResult result;
    result.isCollision = false;
    result.hitPoint = Vector2();

    Vector2 A1 = _end - _start;
    Vector2 A2 = other->_start - _start;
    Vector2 A3 = other->_end - _start;

    bool check1 = A1.IsBetween(A2, A3);

    Vector2 B1 = other->_end - other->_start;
    Vector2 B2 = _start - other->_start;
    Vector2 B3 = _end - other->_start;

    bool check2 = B1.IsBetween(B2, B3);

    result.isCollision = check1 && check2;

    if (result.isCollision)
    {
        float leftTriangle = abs(A1.Cross(A2));
        float rightTriangle = abs(A1.Cross(A3));

        float t = leftTriangle / (leftTriangle + rightTriangle);

        result.hitPoint = LERP(other->_start, other->_end, t);
    }

	return result;
}

