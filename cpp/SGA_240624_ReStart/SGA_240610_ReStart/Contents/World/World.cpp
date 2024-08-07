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
//	// TODO: ���⿡ return ���� �����մϴ�.
//}

void World::DeiMsg()
{
	
}

string World::Num_string(int num)
{
	switch (num)
	{
	case 1:
		return "������ ����";
		break;
	case 2:
		return "������ �ü�";		
		break;
	case 3:
		return "������ ������";
		break;
	default:
		cout << "�߸��� �����Դϴ�." << endl;
		break;
	}
}

void World::Init()
{
	for (int i = 0; i < 10; ++i) 
	{
		_goblin[i] = nullptr; // �迭 �ʱ�ȭ
	}
}

bool World::End()
{
	if (_player->IsDead()) {
		return true;
	}

	if (_computer != nullptr && _computer->IsDead()) {
		cout << "������ ����߽��ϴ�.. ������ �����մϴ�" << endl;
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
		cout << "��� ����� ����߽��ϴ�." << endl;
		return true;
	}

	return false;
}

void World::SponGoblin()
{
	for (int i = 0; i < 10; ++i) 
	{
		if (_goblin[i] != nullptr) delete _goblin[i]; // ���� ��� ����

		// ��� ���� ���� ����
		int hp = RandMon(50, 100);
		int atk = RandMon(1, 10);
		int dropexp = RandMon(1, 1);

		_goblin[i] = new Goblin("��� " + to_string(i + 1), hp, atk, dropexp); // �� ��� ����
	}
	//cout << "��� 10������ �����Ǿ����ϴ�." << endl;
}

bool World::monster_alldeed(Creature* gb[], int gb_count)
{
	for (int i = 0; i < gb_count; ++i)
	{
        if (gb[i] != nullptr && !gb[i]->IsDead())
		{
            return false; // �ϳ��� ��� ������ false
        }
    }
    return true; // ��� �׾����� true
}

void World::SeletPlayer(int num, string name, Creature** creature)
{
	switch (num)
	{
	case PlayerType::NONE:
	{
		cout << "�ٽ� �Է����ּ���." << endl;
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
		cout << "�ٽ� �Է����ּ���." << endl;
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
		cout << "�ٽ� �Է����ּ���." << endl;
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
		cout << "�ٽ� �Է����ּ���." << endl;
	}
	break;
	}
}

void World::Input()
{
	int playerNum = 0;
	int comNum = 0;
	string name;

	cout << "ĳ������ �̸��� �Է����ּ��� : ";
	cin >> name;
	cout << "������ ĳ������ ������ �������ּ���." << endl;
	cout << "< 1. ��� / 2. �ü� / 3. ������ > : ";
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
		cout << count << " ��° �� ������." << endl;

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
	int goblinCount = rand() % 10 + 1; // 1~10 ������ ��� ����
	cout << "�÷��̾ ������ �����մϴ�." << endl;
	cout << "���������� �ִ� 10������ ������ ���Ϳ� ����ĥ�� �ֽ��ϴ�.." << endl;
	Sleep(1000);
	cout << goblinCount << " ������ ����� �ο�ϴ�." << endl;
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
		cout << count << " ��° �� ������." << endl;

		system("pause");

	}
}




void World::Field()
{
	int select;

	cout << "�÷��̾�� �����Ҽ��ֽ��ϴ�." << endl
		<< "�������� �ٷ� �����Ұ�����." << endl
		<< "������ ��������.." << endl << endl;
	Sleep(1000);


	while (true)
	{
		if (_clear) break; // ��ǻ�Ͱ� �׾ Ŭ����Ȼ��¶�� �ٷ� ����.
		system("cls");
		_player->PrintInfo();
		cout << "�����Ͽ� �ּ���." << endl
			<< "< 1. ������ / 2. ����(ȸ��) / 3. ����  >  : ";
		cin >> select;

		switch (select)
		{
		case 1:
		{
			Battle1();

			if (End())
			{
				cout << "����Ͽ����ϴ�." << endl;
					//<< "�÷��̾���� �ο򿡼� ������ �ƴ����� ��� ���� �������ϴ�." << endl; 
				// ���� �������� ������������ ������ߴµ� �����Ƽ� �������.
				system("pause");
			}
		}
			break;
		case 2:
		{
			cout << "������ ���� �մϴ�" << endl;
			Sleep(1000); 
			cout << "�������� ��� ���ظ� ȸ���Ͽ����ϴ�." << endl;
			_player->Full_Hp_Mp();
			_player->PrintInfo();
		}
			break;
		case 3:
		{
			SponGoblin(); // ���� ������ ���� ��� �����
			Battle2(); // �������� ����� �ο��
		}
			break;
		default:
			break;
		}


		if (select == 7777) // ������� ������ġƮ (����ġ 1000 ȹ��)
		{
			_player->GainExp(1000);
		}
		
		if (select == 4444) // ���ؿ� �ӽ� �ڵ�
		{
			cout << "���� ü���� ���� ��ŭ �������� �Խ��ϴ�." << endl;
			_player->TakeDamage(_player->Getcurhp() / 2);
		}

		if(select == 9999) // �׳� �����
		{
			cout << "�����ڵ� �Է� ~ �� ������~";
			break;		
		}
	}
}
