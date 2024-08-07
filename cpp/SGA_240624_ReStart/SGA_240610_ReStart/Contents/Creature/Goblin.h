#pragma once
class Goblin : public Monster
{
public:
 	Goblin(string name, int hp, int atk, int dropexp) : Monster(name, hp, atk, dropexp) {}
	Goblin(int hp, int atk, int dropexp) : Monster(hp,atk,dropexp) {}
	virtual ~Goblin();

	virtual void PrintInfo()override;
	// Player을(를) 통해 상속됨
	void Attack(Creature* other) override;

	virtual int GetDropExp() override { return _dropexp; }

private:

};

