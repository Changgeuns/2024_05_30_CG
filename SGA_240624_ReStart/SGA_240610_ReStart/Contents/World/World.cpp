#include "pch.h"
#include "World.h"

World::World()
	:_player(nullptr),
	_computer(nullptr)
{
	Input();
	Init();
}

World::~World()
{

	if(_player != nullptr)
		delete _player;
	if (_computer != nullptr)
		delete _computer;
	/*if (_goblin != nullptr)
	{
		for (int i = 0; i < 10; ++i) {
			delete _goblin[i];
		}
	}*/
	for (int i = 0; i < 10; ++i)
	{
		if (_goblin[i] != nullptr)
		{
			delete _goblin[i];
		}
	}

}

//World::World(const World& other)
//{
//	_player = new Creature(*other._player);
//}
//
//World& World::operator=(const World& other)
//{
//	// TODO: 여기에 return 문을 삽입합니다.
//}

void World::DeiMsg()
{
	
}

string World::Num_string(int num)
{
	switch (num)
	{
	case 1:
		return "태초의 전사";
		break;
	case 2:
		return "태초의 궁수";		
		break;
	case 3:
		return "태초의 마법사";
		break;
	default:
		cout << "잘못된 접근입니다." << endl;
		break;
	}
}

void World::Init()
{
	for (int i = 0; i < 10; ++i) 
	{
		_goblin[i] = nullptr; // 배열 초기화
	}
}

bool World::End()
{
	if (_player->IsDead()) {
		return true;
	}

	if (_computer != nullptr && _computer->IsDead()) {
		cout << "보스가 사망했습니다.. 게임을 종료합니다" << endl;
		_clear = true;
		return true;
	}

	return false;
}

bool World::End(int gb)
{
	if (_player->IsDead()) {
		return true;
	}

	if (monster_alldeed(_goblin, gb)) {
		cout << "모든 고블린이 사망했습니다." << endl;
		return true;
	}

	return false;
}

void World::SponGoblin()
{
	for (int i = 0; i < 10; ++i) 
	{
		if (_goblin[i] != nullptr) delete _goblin[i]; // 이전 고블린 삭제

		// 고블린 스펙 랜덤 설정
		int hp = RandMon(50, 100);
		int atk = RandMon(1, 10);
		int dropexp = RandMon(1, 1);

		_goblin[i] = new Goblin("고블린 " + to_string(i + 1), hp, atk, dropexp); // 새 고블린 생성
	}
	//cout << "고블린 10마리가 생성되었습니다." << endl;
}

bool World::monster_alldeed(Creature* gb[], int gb_count)
{
	for (int i = 0; i < gb_count; ++i)
	{
        if (gb[i] != nullptr && !gb[i]->IsDead())
		{
            return false; // 하나라도 살아 있으면 false
        }
    }
    return true; // 모두 죽었으면 true
}

void World::SeletPlayer(int num, string name, Creature** creature)
{
	switch (num)
	{
	case PlayerType::NONE:
	{
		cout << "다시 입력해주세요." << endl;
	}
	break;
	case PlayerType::KNIGHT:
	{
		*creature = new Knight(name, 500, 15);
	}
	break;
	case PlayerType::ARCHER:
	{
		*creature = new Archer(name, 300, 30);
	}
	break;
	case PlayerType::MAGE:
	{
		*creature = new Mage(name, 100, 80);
	}
	break;
	default:
	{
		cout << "다시 입력해주세요." << endl;
	}
	break;
	}
}

void World::SeletComputer(int num, string name, Creature** creature)
{
	switch (num)
	{
	case PlayerType::NONE:
	{
		cout << "다시 입력해주세요." << endl;
	}
	break;
	case PlayerType::KNIGHT:
	{
		*creature = new Knight(name, 3000, 50);
	}
	break;
	case PlayerType::ARCHER:
	{
		*creature = new Archer(name, 1500, 50);
	}
	break;
	case PlayerType::MAGE:
	{
		*creature = new Mage(name, 1000, 200);
	}
	break;
	default:
	{
		cout << "다시 입력해주세요." << endl;
	}
	break;
	}
}

void World::Input()
{
	int playerNum = 0;
	int comNum = 0;
	string name;

	cout << "캐릭터의 이름을 입력해주세요 : ";
	cin >> name;
	cout << "생성할 캐릭터의 직업을 선택해주세요." << endl;
	cout << "< 1. 기사 / 2. 궁수 / 3. 마법사 > : ";
	cin >> playerNum;
	comNum = rand() % 3 + 1; // 1~ 3
	

	SponGoblin();
	SeletPlayer(playerNum, name, &_player);
	SeletComputer(comNum, Num_string(comNum), &_computer);
	system("pause");
}

void World::Battle1()
{
	int count = 0;
	while (true)
	{
		system("cls");
		count++;
		_player->PrintInfo();
		_computer->PrintInfo();

		_player->Attack(_computer);
		Sleep(50);
		_computer->Attack(_player);
		cout << count << " 번째 턴 진행중." << endl;

		system("pause");

		if (End())
		{
			_computer->Full_Hp_Mp();	
			break;
		}

	}


}

void World::Battle2()
{
	int goblinCount = rand() % 10 + 1; // 1~10 마리의 고블린 선택
	cout << "플레이어가 던전에 진입합니다." << endl;
	cout << "던전에서는 최대 10마리의 램덤한 몬스터와 마주칠수 있습니다.." << endl;
	Sleep(1000);
	cout << goblinCount << " 마리의 고블린과 싸웁니다." << endl;
	system("pause");
	int count = 0;

	while (true)
	{
		system("cls");
		count++;
		_player->PrintInfo();

		for (int i = 0; i < goblinCount; ++i) 
		{
			if (_goblin[i] != nullptr && !_goblin[i]->IsDead()) 
			{
				_goblin[i]->PrintInfo();
			}
		}

		for (int i = 0; i < goblinCount; ++i)
		{
			if (_goblin[i] != nullptr && !_goblin[i]->IsDead()) 
			{

				_player->Attack(_goblin[i]);

				if (_goblin[i]->IsDead())
				{
					int Dropexp = _goblin[i]->GetDropExp();
					_player->GainExp(Dropexp);

					//_goblin[i] = nullptr;
				}
				else
				{
					_goblin[i]->Attack(_player);
				}
			}
		}
		if (End(goblinCount))
		{
			system("pause");
			break;
		}
		cout << count << " 번째 턴 진행중." << endl;

		system("pause");

	}
}




void World::Field()
{
	int select;

	cout << "플레이어는 선택할수있습니다." << endl
		<< "보스에게 바로 도전할것인지." << endl
		<< "성장을 도모할지.." << endl << endl;
	Sleep(1000);


	while (true)
	{
		if (_clear) break; // 컴퓨터가 죽어서 클리어된상태라면 바로 종료.
		system("cls");
		_player->PrintInfo();
		cout << "선택하여 주세요." << endl
			<< "< 1. 보스런 / 2. 마을(회복) / 3. 던전  >  : ";
		cin >> select;

		switch (select)
		{
		case 1:
		{
			Battle1();

			if (End())
			{
				cout << "사망하였습니다." << endl;
					//<< "플레이어와의 싸움에서 보스가 꺠달음을 얻고 더욱 강해집니다." << endl; 
				// 점점 강해지는 보스형식으로 만들까했는데 귀찮아서 여기까지.
				system("pause");
			}
		}
			break;
		case 2:
		{
			cout << "마을로 진입 합니다" << endl;
			Sleep(1000); 
			cout << "여관에서 모든 피해를 회복하였습니다." << endl;
			_player->Full_Hp_Mp();
			_player->PrintInfo();
		}
			break;
		case 3:
		{
			SponGoblin(); // 다음 전투를 위해 고블린 재생성
			Battle2(); // 던전에서 고블린과 싸우기
		}
			break;
		default:
			break;
		}


		if (select == 7777) // 스펙업용 레벨업치트 (경험치 1000 획득)
		{
			_player->GainExp(1000);
		}
		
		if (select == 4444) // 자해용 임시 코드
		{
			cout << "현제 체력의 절반 만큼 데미지를 입습니다." << endl;
			_player->TakeDamage(_player->Getcurhp() / 2);
		}

		if(select == 9999) // 그냥 종료용
		{
			cout << "자폭코드 입력 ~ 응 뒤질게~";
			break;		
		}
	}
}
