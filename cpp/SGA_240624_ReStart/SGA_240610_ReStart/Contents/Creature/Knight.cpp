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
	cout << exp << " ����ġ ȹ��! " << endl;
	cout << "����ġ : " << _exp << " / " << _maxexp << endl;
	if (_exp >= _maxexp)
	{
		LevelUp();
	}
}

void Knight::PrintInfo()
{
	cout << _name <<"�� ���� ====" << endl;
	cout << "�̸� : " << _name << endl;
	cout << "���� : ���" << endl;
	cout << "���� : " << _level << endl;
	cout << "����ġ : " << _exp << " / " << _maxexp << endl;
	cout << " HP : " << _curHp << " / " << _maxHp << endl;
	cout << " ���ݷ� : " << _atk << endl;
}

void Knight::Attack(Creature* other)
{
	this->Creature::PreAttack(other);

	float ratio = (float)_curHp / (float)_maxHp;

	if (ratio < 0.5f)
	{
		// ���� ü���� 50���� �̸�
		cout << "ü���� 50���� �̸��̵Ǿ ����ȭ�ߵ�!(������ 2��)" << endl;
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
		_maxHp += 100; // ������ �� ü�� ����
		_curHp = _maxHp;
		_atk += 5; // ������ �� ���ݷ� ����

		cout << "������! ���� ����: " << _level << endl;
		cout << "���� ���������� �ʿ��� ����ġ : " << _exp << " / " << _maxexp << endl;
		cout << "��� ���¸� ȸ���ϰ� ü��(100)�� ���ݷ�(5)�� �����մϴ�!" << endl;
		Sleep(500);
	}
}
