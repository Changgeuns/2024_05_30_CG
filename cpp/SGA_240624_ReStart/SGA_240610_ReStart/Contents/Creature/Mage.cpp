#include "pch.h"
#include "Mage.h"

Mage::Mage(string name, int hp, int atk)
	:Player(name, hp, atk),
	_curMp(10), _maxMp(_curMp)
{
}

Mage::~Mage()
{
}

void Mage::GainExp(int exp)
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

void Mage::PrintInfo()
{
	cout << _name << "의 정보 ====" << endl;
	cout << "이름 : " << _name << endl;
	cout << "직업 : 마법사" << endl;
	cout << "레벨 : " << _level << endl;
	cout << "경험치 : " << _exp << " / " << _maxexp << endl;
	cout << " HP : " << _curHp << " / " << _maxHp << endl;
	cout << " MP : " << _curMp << " / " << _maxMp << endl;
	cout << " 공격력 : " << _atk << endl;

}

void Mage::Attack(Creature* other)
{
	PreAttack(other);

	if (_curMp <= 4)
	{
		cout << "마나가 부족해서 공격에 실패했습니다." << endl;
		cout << "자동으로 명상에 돌입 한턴 쉬고 마나를 50회복합니다." << endl << endl;
		_curMp += 50;
		if (_curMp > _maxMp) _curMp = _maxMp;
		_this_atk = 0; // 공격을 못하니 데미지는 0
		return;
	}
	_this_atk = _atk;
	other->TakeDamage(_this_atk); // 법사는 공격만 쉬면되서 굳이 안해도됨
	_curMp -= 5;
}

void Mage::LevelUp()
{
	while (_exp >= _maxexp)
	{
		_exp -= _maxexp;
		_level++;
		_maxexp = Fibonacci(_level);
		//cout << "exp : " << _exp << endl;
		//cout << "maxexp : " << _Max_exp << endl;
		_maxHp += 20; // 레벨업 시 체력 증가
		_curHp = _maxHp;
		_maxMp += 5;
		_curMp = _maxMp;
		_atk += 20; // 레벨업 시 공격력 증가

		cout << "레벨업! 현재 레벨: " << _level << endl;
		cout << "다음 레벨업까지 필요한 경험치 : " << _exp << " / " << _maxexp << endl;
		cout << "모든 상태를 회복하고 체력(20),마나(5), 공격력(20)이 증가합니다!" << endl;
		Sleep(500);
	}
}
