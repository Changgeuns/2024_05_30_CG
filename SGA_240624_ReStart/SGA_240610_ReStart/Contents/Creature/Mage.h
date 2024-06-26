#pragma once
class Mage : public Player
{
public:
	Mage(string name, int hp, int atk);
	Mage(int hp, int atk, int mp) : Player(hp,atk), _curMp(mp), _maxMp(mp) {}
	~Mage();




	virtual void GainExp(int exp) override;

	virtual void PrintInfo()override;
	virtual void Full_Hp_Mp()override { _curHp = _maxHp; _curMp = _maxMp; }
	// Player을(를) 통해 상속됨
	void Attack(Creature* other) override;
private:
	int _curMp;
	int _maxMp;

	virtual void LevelUp()override;
};

