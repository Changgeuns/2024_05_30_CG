#include "pch.h"
#include "HopGoblin.h"

void HopGoblin::PrintInfo()
{
	cout << _name << " �� ���� ====" << endl;
	cout << "�̸� : " << _name << endl;
	cout << " HP : " << _curHp << " / " << _maxHp << endl;
	cout << " ���ݷ� : " << _atk << endl;
	cout << " ��� ����ġ : " << _dropexp << endl;
}

void HopGoblin::Attack(Creature* other)
{
	this->Creature::PreAttack(other);

	other->TakeDamage(_atk);
}

void HopGoblin::Attack_Hop(vector<Creature*>& other)
{
//	this->Creature::PreAttack(other);
//	other->TakeDamage(_atk);

    for (Creature* pl : other)
    {
        if (pl == nullptr || pl->IsDead())
            continue;

        pl->TakeDamage(_atk);

        if (pl->IsDead())
        {
            continue;
        }
    }
}


