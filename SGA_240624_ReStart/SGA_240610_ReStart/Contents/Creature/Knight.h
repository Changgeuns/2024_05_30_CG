#pragma once
class Knight : public Player
{
public:
	Knight(string name, int hp, int atk);
	Knight(int hp, int atk) : Player(hp, atk) {}
	virtual ~Knight();



	virtual void GainExp(int exp) override;

	virtual void PrintInfo()override;

	// Player을(를) 통해 상속됨
	virtual void Attack(Creature* other) override;
private:
	virtual void LevelUp()override;

};

