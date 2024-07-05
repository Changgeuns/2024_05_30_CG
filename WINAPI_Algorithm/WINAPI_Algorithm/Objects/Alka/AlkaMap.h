#pragma once
class AlkaMap
{
public:
	AlkaMap();
	~AlkaMap();

	void Update();
	void Render(HDC hdc);

	void IsCollision(shared_ptr<class AlkaBall> ball);


	void IsCollisionUpDwon(shared_ptr<class AlkaBall> ball);
	void IsCollisionRightLeft(shared_ptr<class AlkaBall> ball);

private:
	vector<vector<shared_ptr<class AlkaRect>>> _rect;

};

