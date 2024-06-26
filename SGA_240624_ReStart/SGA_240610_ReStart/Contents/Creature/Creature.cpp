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
	cout << "의 정보 ======" << endl;
	cout << "이름 : " << _name << endl;
	cout << " HP : " << _curHp << " / " << _maxHp << endl;
	cout << " 공격력 : " << _atk << endl;
}

void Creature::PreAttack(Creature* other)
{
	//cout << _name << " 이" << other->_name << " 에게 공격을 시도합니다." << endl;
	cout << _name << "이(가) " << other->GetName() << "을(를) 공격했습니다!" << endl;

}

void Creature::TakeDamage(int amount)//, Creature* attacker = nullptr)
{
	cout << _name << "이(가) " << amount << "의 피해를 입었습니다!" << endl << endl;
	_curHp -= amount;

	if (_curHp <= 0)
	{
		_curHp = 0;
		cout << endl << _name << "이(가) 쓰러졌습니다!" << endl;

	}

}

void Creature::PK_Bosspowerup()
{
	_maxHp *= 2;
	_curHp = _maxHp;// 체략회복
	_atk *= 2;
}
