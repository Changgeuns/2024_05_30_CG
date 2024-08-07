#pragma once
class Creature
{
public:
	Creature(string name, int hp, int atk);
	Creature(int hp, int att) : _curHp(hp), _atk(att), _maxHp(hp), _name("공백"), _this_atk(att){}

	virtual ~Creature();

	// 멤버함수 : 기능
	virtual void PrintInfo();
	void PreAttack(Creature* other);
	virtual void Attack(Creature* other) abstract; // 순수 가상함수 = 0
	
	
	virtual void TakeDamage(int amount);//, Creature* attacker = nullptr);
	void SetName(string name) { _name = name; }
	virtual void Full_Hp_Mp() { _curHp = _maxHp; }


	bool IsDead() { return _curHp <= 0; }

	const string& GetName() { return _name; }
	const int& Getcurhp() { return _curHp; }
	void PK_Bosspowerup();

	virtual int GetDropExp() { return 0; }  // 기본값은 0, 몬스터에서 오버라이드
	virtual void GainExp(int exp) {}         // 기본값은 빈 함수, 플레이어에서 오버라이드
	virtual int Getthis_TakeDamage() { return _this_atk; }

	void SetAggro_DMG(int ag) { aggro_dmg += ag; }
	int GetAggro_DMG() { return aggro_dmg; }

protected: // 멤버변수 : 속성
	string _name;
	int _curHp;
	int _maxHp;
	int _atk;
	int _this_atk;


	int aggro_dmg = 0;
};

