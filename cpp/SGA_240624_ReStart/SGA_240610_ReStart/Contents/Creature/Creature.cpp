#include "pch.h"
#include "Creature.h"

Creature::Creature(string name, int hp, int atk)
	:_name(name), _curHp(hp), _atk(atk), _maxHp(hp)
	, _this_atk(atk)
{

}

Creature::~Creature()
{
}

void Creature::PrintInfo()
{
	cout << "�� ���� ======" << endl;
	cout << "�̸� : " << _name << endl;
	cout << " HP : " << _curHp << " / " << _maxHp << endl;
	cout << " ���ݷ� : " << _atk << endl;
}

void Creature::PreAttack(Creature* other)
{
	//cout << _name << " ��" << other->_name << " ���� ������ �õ��մϴ�." << endl;
	cout << _name << "��(��) " << other->GetName() << "��(��) �����߽��ϴ�!" << endl;

}

void Creature::TakeDamage(int amount)//, Creature* attacker = nullptr)
{
	cout << _name << "��(��) " << amount << "�� ���ظ� �Ծ����ϴ�!" << endl << endl;
	_curHp -= amount;

	if (_curHp <= 0)
	{
		_curHp = 0;
		cout << endl << _name << "��(��) ���������ϴ�!" << endl;

	}

}

void Creature::PK_Bosspowerup()
{
	_maxHp *= 2;
	_curHp = _maxHp;// ü��ȸ��
	_atk *= 2;
}
