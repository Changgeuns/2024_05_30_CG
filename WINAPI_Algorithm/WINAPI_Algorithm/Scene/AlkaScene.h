#pragma once
class AlkaBall;

class AlkaScene : public Scene
{
public:
	AlkaScene();
	~AlkaScene();

	void Update() override;
	void Render(HDC hdc) override;

private:
	shared_ptr<class AlkaPlayer> _playerBar;
};

