#pragma once
#include "Monster.h"
class HopGoblin : public Monster
{
public:
	HopGoblin(string name, int hp, int atk, int dropexp) : Monster(name, hp, atk, dropexp) {}//, _aggro(0) {}
	HopGoblin(int hp, int atk, int dropexp) : Monster(hp, atk, dropexp) {} //, _aggro(0) {}
	virtual ~HopGoblin() {}

	virtual void PrintInfo()override;
	// Player을(를) 통해 상속됨
	void Attack(Creature* other) override;
	void Attack_Hop(vector<Creature*>& other);

	virtual int GetDropExp() override { return _dropexp; }

	
private:

};

