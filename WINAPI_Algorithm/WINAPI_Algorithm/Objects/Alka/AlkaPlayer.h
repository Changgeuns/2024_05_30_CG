#pragma once
class AlkaBall;

class AlkaPlayer
{
public:
	AlkaPlayer();
	~AlkaPlayer();

	void Update();
	void Render(HDC hdc);

	void Move();
	void FirstBallShot();

private:
	shared_ptr<Collider> _Bar;
	shared_ptr<class AlkaRect> _rects;

	shared_ptr<AlkaBall> _Firstball;
	bool firstShot = false;
	vector<shared_ptr<AlkaBall>> _balls;

	Vector2 barMovement = Vector2(0, 0);
	
};

