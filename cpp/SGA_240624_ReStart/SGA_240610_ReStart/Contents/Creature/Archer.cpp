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
	cout << exp << " ����ġ ȹ��! " << endl;
	cout << "����ġ : " << _exp << " / " << _maxexp << endl;
	if (_exp >= _maxexp)
	{
		LevelUp();
	}
}

void Archer::PrintInfo()
{
	cout << _name << " �� ���� ====" << endl;
	cout << "�̸� : " << _name << endl;
	cout << "���� : �ü�" << endl;
	cout << "���� : " << _level << endl;
	cout << "����ġ : " << _exp << " / " << _maxexp << endl;
	cout << " HP : " << _curHp << " / " << _maxHp << endl;
	cout << " ���ݷ� : " << _atk << endl;
}

void Archer::Attack(Creature* other)
{
	this->Creature::PreAttack(other); // ����Լ��� ȣ���ϱ����� ���� ... ��ü�� �׻� �־���Ѵ�
	int cre = rand() % 100 +1; // 1~100  100���� ���� ���� �Է�


	cout << _name << "�� ��Ű���̽�(30 ���� ũ��Ƽ��) : " << cre << endl;
	if (cre <= 30) // �����Ѽ��� 1~30 30�� �� 30���ζ�� ũ��Ƽ��
	{
		// ũ��Ƽ�� ������ 3��
		cout << "ũ��Ƽ�� ��! (������ 3��)" << endl;
		_this_atk = _atk * 3;
		other->TakeDamage(_this_atk);
	}
	else
	{
		_this_atk = _atk;
		// �ƴ϶�� ��� ����
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
		_maxHp += 50; // ������ �� ü�� ����
		_curHp = _maxHp;
		_atk += 10; // ������ �� ���ݷ� ����

		cout << "������! ���� ����: " << _level << endl;
		cout << "���� ���������� �ʿ��� ����ġ : " << _exp << " / " << _maxexp << endl;
		cout << "��� ���¸� ȸ���ϰ� ü��(50)�� ���ݷ�(10)�� �����մϴ�!" << endl;
		Sleep(500);
	}
}
