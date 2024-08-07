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
    cout << exp << " 경험치 획득! " <<  endl;
    cout << "추가로 레벨업까지 필요한 경험치 : " << _exp << " / " << _maxexp << endl;

    if (_exp >= _maxexp) 
    {
        LevelUp();
    }
}


void Player::LevelUp()
{
    while (_exp >= _maxexp)
    {
        cout << "레벨업~!@" << endl;
        _level++;
        _exp -= _maxexp;
        _maxexp = Fibonacci(_level);
        //cout << "exp : " << _exp << endl;
        //cout << "maxexp : " << _Max_exp << endl;
        cout << "레벨업! 현재 레벨: " << _level << ", 다음 레벨까지의 경험치: " << _maxexp << endl;

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
