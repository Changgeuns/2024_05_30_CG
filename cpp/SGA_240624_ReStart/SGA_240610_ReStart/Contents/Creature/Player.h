#pragma once
class Player : public Creature
{
public:
	Player(string name, int hp, int atk);
	Player(int hp, int atk) : Creature(hp,atk), _maxexp(1), _level(1), _exp(0) {}
	virtual ~Player();

	virtual void GainExp(int exp) override;

protected:
	int _level;
	int _maxexp;
	int _exp;


	virtual void LevelUp();
	virtual int Fibonacci(int n);
};

