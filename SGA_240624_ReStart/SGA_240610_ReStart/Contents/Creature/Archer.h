#pragma once
class Archer : public Player
{
public:
	Archer(string name, int hp, int atk);
	Archer(int hp , int atk) : Player(hp,atk) {}
	virtual ~Archer();


	virtual void GainExp(int exp) override;

	virtual void PrintInfo()override;
	// Player을(를) 통해 상속됨
	virtual void Attack(Creature* other) override;
private:
	virtual void LevelUp()override;

};

