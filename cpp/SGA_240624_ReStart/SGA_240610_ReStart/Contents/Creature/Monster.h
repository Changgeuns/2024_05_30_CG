#pragma once
class Monster : public Creature
{
public:
	Monster(string name, int hp, int atk, int dropexp = 0) :Creature(name, hp, atk), _dropexp(dropexp) {}
	Monster(int hp, int atk, int dropexp = 0) :Creature(hp,atk), _dropexp(dropexp) {}
	virtual ~Monster();


	virtual int GetDropExp() override { return _dropexp; }

protected:
	int _dropexp;
};

