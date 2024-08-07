#include "pch.h"
#include "Player.h"

Player::Player(string name, int hp, int atk)
	:Creature(name,hp,atk), 
	_exp(0), _maxexp(1), _level(1)
{

}

Player::~Player()
{

}

void Player::GainExp(int exp)
{
    _exp += exp;
    cout << exp << " ����ġ ȹ��! " <<  endl;
    cout << "�߰��� ���������� �ʿ��� ����ġ : " << _exp << " / " << _maxexp << endl;

    if (_exp >= _maxexp) 
    {
        LevelUp();
    }
}


void Player::LevelUp()
{
    while (_exp >= _maxexp)
    {
        cout << "������~!@" << endl;
        _level++;
        _exp -= _maxexp;
        _maxexp = Fibonacci(_level);
        //cout << "exp : " << _exp << endl;
        //cout << "maxexp : " << _Max_exp << endl;
        cout << "������! ���� ����: " << _level << ", ���� ���������� ����ġ: " << _maxexp << endl;

    }
}

int Player::Fibonacci(int n)
{
    if (n <= 2)
        return 1;
    int fib1 = 1;
    int fib2 = 1;
    int fib = 0;
    for (int i = 3; i <= n; ++i) {
        fib = fib1 + fib2;
        fib1 = fib2;
        fib2 = fib;
    }
    return fib;
}
