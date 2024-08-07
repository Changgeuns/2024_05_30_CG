#pragma once
class World
{
public:
	enum PlayerType {
		NONE  = 0,
		KNIGHT = 1,
		ARCHER = 2,
		MAGE = 3
	};

	World();
	~World();
	// ���� ���� : ���������, ������Կ����� �Ѵ�
	// ���������
	//World(const World& other);
	// ������� ������
	//World& operator=(const World& other);

	void DeiMsg();
	string Num_string(int num);
	void Init(); // �ʱ�ȭ

	bool End();
	bool End(int gb); // �������� ���� �����ε�
	

	void Battle1();
	void Battle2(); // ����


	void Field();
private:
	Creature* _player;
	Creature* _computer;
	Creature* _goblin[10];
	bool _clear = false; // �������� ����

	void SeletPlayer(int num, string name, Creature** creature);
	void SeletComputer(int num, string name, Creature** creature);
	int RandMon(int min, int max) { return rand() % (max - min + 1) + min; }
	void SponGoblin();
	bool monster_alldeed(Creature* gb[], int gb_count);
	void Input();
};

