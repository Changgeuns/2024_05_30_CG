#pragma once
class AlkaBall
{
public:
	AlkaBall();
	AlkaBall(Vector2 pos);
	~AlkaBall();

	void Update();
	void Render(HDC hdc);

	void SetActive(bool isActive) { _isActive = isActive; }

	void FirstBallShot(Vector2 startPos, Vector2 direction);

	shared_ptr<Collider>& GetFirstBall() { return _ball; }
	void SetDirection(Vector2 direction) { _direction = direction; }
	Vector2 GetDirection() { return _direction; }

	void OutControll();
	void RectControll(shared_ptr<Collider> rect);
private:
	bool _isActive = false;
	shared_ptr<Collider> _ball;
	Vector2 _direction = Vector2(0, 1);
	float _speed = 7.0f;

	Vector2 _downVector = Vector2();


};

