#include "pch.h"
#include "Goblin.h"

Goblin::~Goblin()
{
}

void Goblin::PrintInfo()
{
	cout << _name << " 의 정보 ====" << endl;
	cout << "이름 : " << _name << endl;
	cout << " HP : " << _curHp << " / " << _maxHp << endl;
	cout << " 공격력 : " << _atk << endl;
	cout << " 드랍 경험치 : " << _dropexp << endl;
}

void Goblin::Attack(Creature* other)
{
	this->Creature::PreAttack(other); 

	other->TakeDamage(_atk);
}
