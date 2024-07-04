#pragma once
class AlkaMap
{
public:
	AlkaMap();
	~AlkaMap();

	void Update();
	void Render(HDC hdc);

private:
	vector<vector<shared_ptr<class AlkaRect>>> _rect;
};

