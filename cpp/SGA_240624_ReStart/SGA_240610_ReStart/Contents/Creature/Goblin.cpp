#include "pch.h"
#include "Goblin.h"

Goblin::~Goblin()
{
}

void Goblin::PrintInfo()
{
	cout << _name << " �� ���� ====" << endl;
	cout << "�̸� : " << _name << endl;
	cout << " HP : " << _curHp << " / " << _maxHp << endl;
	cout << " ���ݷ� : " << _atk << endl;
	cout << " ��� ����ġ : " << _dropexp << endl;
}

void Goblin::Attack(Creature* other)
{
	this->Creature::PreAttack(other); 

	other->TakeDamage(_atk);
}
