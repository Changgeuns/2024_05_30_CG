#include "pch.h"
#include "Archer.h"

Archer::Archer(string name, int hp, int atk)
	:Player(name, hp, atk)
{
}

Archer::~Archer()
{
}

void Archer::GainExp(int exp)
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

void Archer::PrintInfo()
{
	cout << _name << " 의 정보 ====" << endl;
	cout << "이름 : " << _name << endl;
	cout << "직업 : 궁수" << endl;
	cout << "레벨 : " << _level << endl;
	cout << "경험치 : " << _exp << " / " << _maxexp << endl;
	cout << " HP : " << _curHp << " / " << _maxHp << endl;
	cout << " 공격력 : " << _atk << endl;
}

void Archer::Attack(Creature* other)
{
	this->Creature::PreAttack(other); // 멤버함수를 호출하기위한 조건 ... 객체가 항상 있어야한다
	int cre = rand() % 100 +1; // 1~100  100개의 숫자 램덤 입력


	cout << _name << "의 럭키다이스(30 이하 크리티컬) : " << cre << endl;
	if (cre <= 30) // 램덤한수가 1~30 30개 즉 30프로라면 크리티컬
	{
		// 크리티컬 데미지 3배
		cout << "크리티컬 샷! (데미지 3배)" << endl;
		_this_atk = _atk * 3;
		other->TakeDamage(_this_atk);
	}
	else
	{
		_this_atk = _atk;
		// 아니라면 통상 공격
		other->TakeDamage(_this_atk);
	}
}

void Archer::LevelUp()
{
	while (_exp >= _maxexp)
	{
		_exp -= _maxexp;
		_level++;
		_maxexp = Fibonacci(_level);
		//cout << "exp : " << _exp << endl;
		//cout << "maxexp : " << _Max_exp << endl;
		_maxHp += 50; // 레벨업 시 체력 증가
		_curHp = _maxHp;
		_atk += 10; // 레벨업 시 공격력 증가

		cout << "레벨업! 현재 레벨: " << _level << endl;
		cout << "다음 레벨업까지 필요한 경험치 : " << _exp << " / " << _maxexp << endl;
		cout << "모든 상태를 회복하고 체력(50)과 공격력(10)이 증가합니다!" << endl;
		Sleep(500);
	}
}
