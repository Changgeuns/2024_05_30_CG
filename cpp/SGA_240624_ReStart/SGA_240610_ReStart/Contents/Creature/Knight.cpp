#include "pch.h"
#include "Knight.h"

Knight::Knight(string name, int hp, int atk)
	: Player(name, hp, atk)
{
}

Knight::~Knight()
{
}

void Knight::GainExp(int exp)
{
	_exp += exp;

	cout << endl;
	cout << exp << " 경험치 획득! " << endl;
	cout << "경험치 : " << _exp << " / " << _maxexp << endl;
	if (_exp >= _maxexp)
	{
		LevelUp();
	}
}

void Knight::PrintInfo()
{
	cout << _name <<"의 정보 ====" << endl;
	cout << "이름 : " << _name << endl;
	cout << "직업 : 기사" << endl;
	cout << "레벨 : " << _level << endl;
	cout << "경험치 : " << _exp << " / " << _maxexp << endl;
	cout << " HP : " << _curHp << " / " << _maxHp << endl;
	cout << " 공격력 : " << _atk << endl;
}

void Knight::Attack(Creature* other)
{
	this->Creature::PreAttack(other);

	float ratio = (float)_curHp / (float)_maxHp;

	if (ratio < 0.5f)
	{
		// 현재 체력이 50프로 미만
		cout << "체력이 50프로 미만이되어서 광폭화발동!(데미지 2배)" << endl;
		_this_atk = _atk * 2;
		other->TakeDamage(_this_atk);
	}
	else
	{
		_this_atk = _atk;
		other->TakeDamage(_this_atk);
	}
}

void Knight::LevelUp()
{
	while (_exp >= _maxexp)
	{
		_exp -= _maxexp;
		_level++;
		_maxexp = Fibonacci(_level);
		//cout << "exp : " << _exp << endl;
		//cout << "maxexp : " << _Max_exp << endl;
		_maxHp += 100; // 레벨업 시 체력 증가
		_curHp = _maxHp;
		_atk += 5; // 레벨업 시 공격력 증가

		cout << "레벨업! 현재 레벨: " << _level << endl;
		cout << "다음 레벨업까지 필요한 경험치 : " << _exp << " / " << _maxexp << endl;
		cout << "모든 상태를 회복하고 체력(100)과 공격력(5)이 증가합니다!" << endl;
		Sleep(500);
	}
}
