#pragma once

#define MAXCOUNT_X 10
#define MAXCOUNT_Y 3

class AlkaRect : public RectCollider
{
public:
	enum class RectType
	{
		ALIVE,
		DIE
	};

	AlkaRect();
	~AlkaRect();

	void Update();
	void Render(HDC hdc);


private:
	RectType _type = RectType::ALIVE;

	vector<HBRUSH> _brushes;
};

