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
	// 깊은 복사 : 복사생성자, 복사대입연산자 둘다
	// 복사생성자
	//World(const World& other);
	// 복사대입 연산자
	//World& operator=(const World& other);

	void DeiMsg();
	string Num_string(int num);
	void Init(); // 초기화

	bool End();
	bool End(int gb); // 고블린사용을 위해 오버로딩
	

	void Battle1();
	void Battle2(); // 과제


	void Field();
private:
	Creature* _player;
	Creature* _computer;
	Creature* _goblin[10];
	bool _clear = false; // 게임종료 조건

	void SeletPlayer(int num, string name, Creature** creature);
	void SeletComputer(int num, string name, Creature** creature);
	int RandMon(int min, int max) { return rand() % (max - min + 1) + min; }
	void SponGoblin();
	bool monster_alldeed(Creature* gb[], int gb_count);
	void Input();
};

