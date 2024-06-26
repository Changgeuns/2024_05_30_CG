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
	cout << exp << " ����ġ ȹ��! " << endl;
	cout << "����ġ : " << _exp << " / " << _maxexp << endl;
	if (_exp >= _maxexp)
	{
		LevelUp();
	}
}

void Mage::PrintInfo()
{
	cout << _name << "�� ���� ====" << endl;
	cout << "�̸� : " << _name << endl;
	cout << "���� : ������" << endl;
	cout << "���� : " << _level << endl;
	cout << "����ġ : " << _exp << " / " << _maxexp << endl;
	cout << " HP : " << _curHp << " / " << _maxHp << endl;
	cout << " MP : " << _curMp << " / " << _maxMp << endl;
	cout << " ���ݷ� : " << _atk << endl;

}

void Mage::Attack(Creature* other)
{
	PreAttack(other);

	if (_curMp <= 4)
	{
		cout << "������ �����ؼ� ���ݿ� �����߽��ϴ�." << endl;
		cout << "�ڵ����� ��� ���� ���� ���� ������ 50ȸ���մϴ�." << endl << endl;
		_curMp += 50;
		if (_curMp > _maxMp) _curMp = _maxMp;
		_this_atk = 0; // ������ ���ϴ� �������� 0
		return;
	}
	_this_atk = _atk;
	other->TakeDamage(_this_atk); // ����� ���ݸ� ����Ǽ� ���� ���ص���
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
		_maxHp += 20; // ������ �� ü�� ����
		_curHp = _maxHp;
		_maxMp += 5;
		_curMp = _maxMp;
		_atk += 20; // ������ �� ���ݷ� ����

		cout << "������! ���� ����: " << _level << endl;
		cout << "���� ���������� �ʿ��� ����ġ : " << _exp << " / " << _maxexp << endl;
		cout << "��� ���¸� ȸ���ϰ� ü��(20),����(5), ���ݷ�(20)�� �����մϴ�!" << endl;
		Sleep(500);
	}
}
