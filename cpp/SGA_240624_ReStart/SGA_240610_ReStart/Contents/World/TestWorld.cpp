#include "pch.h"
#include "TestWorld.h"

TestWorld::TestWorld()
{
    P_Use.resize(10);
	Init();
}

TestWorld::~TestWorld()
{
    /*delete H_goblin;

    for (auto player : P_Use)
    {
        delete player;
    }*/
}

void TestWorld::Init()
{
    SpawnUse();
    SpawnH_gb();
}

//bool TestWorld::End(int P_size)
//{
    //if(H_goblin )
//}

void TestWorld::SpawnUse()
{
    P_Use.clear();
    for (int i = 0; i < 10; ++i)
    {
        int type = rand() % 3 + 1; // 1: ���, 2: �ü�, 3: ������
        string name = "���谡 " + to_string(i + 1);

        Creature* player = nullptr;
        switch (type)
        {
        case 1:
            shared_ptr<Creature> player = make_shared<Knight>(name, 500, 30);
            break;
        case 2:
            shared_ptr<Creature> player = make_shared<Archer>(name, 300, 50);
            break;
        case 3:
            shared_ptr<Creature> player = make_shared<Mage>(name, 200, 70);
            break;
        }

        if (player != nullptr)
        {
            P_Use.push_back(player);
        }
    }
}

void TestWorld::SpawnH_gb()
{
    H_goblin = make_shared<HopGoblin>("ȩ ���", 3000, 100, 1000); // new HopGoblin("ȩ ���", 3000, 100, 1000);
}

void TestWorld::Battle()
{
    int counts = 0;

    while (true)
    {
        system("cls");
        counts++;
        vector<Creature*> aggro = GetTopAttacker();
        H_goblin->PrintInfo();

        for (int i = 0; i < P_Use.size(); i++)
        {
            if (P_Use[i] != nullptr && !P_Use[i]->IsDead())
            {
                P_Use[i]->PrintInfo();
                cout << "�⿩��/��׷� : " << P_Use[i]->GetAggro_DMG() << endl;
            }
        }

       // ������ ����
        if (H_goblin->IsDead())
        {
            for (int i = 0; i < 10; i++)
            {
                int Dropexp = H_goblin->GetDropExp();
                P_Use[i]->GainExp(Dropexp);
            }
        }
        else
        {      
            HopGoblin* H_goblins = dynamic_cast<HopGoblin*>(H_goblin);
            H_goblins->Attack_Hop(aggro);
        }
    
        for (int i = 0; i < P_Use.size(); i++)
        {    

            if (P_Use[i] != nullptr && !P_Use[i]->IsDead())
            {
                P_Use[i]->Attack(H_goblin);
                P_Use[i]->SetAggro_DMG(P_Use[i]->Getthis_TakeDamage());
            }

        }

        aggro.clear();


        cout << counts << " ��° �� ������." << endl;

        if (End())
        {
            system("pause");
            break;
        }
        cout << " ===== �� ��׷� ���� =====" << endl;
        sort(P_Use.begin(), P_Use.end(), [](Creature* a, Creature* b)->bool
            {
                return a->GetAggro_DMG() > b->GetAggro_DMG();
            });
        for (int i = 0; i < P_Use.size(); i++)
        {
            cout << i + 1 << "�� " << P_Use[i]->GetName() << " / �Ѱ� ��׷� : " << P_Use[i]->GetAggro_DMG();
            if (P_Use[i]->IsDead()) cout << "(���)";
            cout << endl;
        }
        system("pause");

    }

}

bool TestWorld::Player_All_deed(vector<Creature*> pl)
{
    for (int i = 0; i < pl.size(); i++)
    {
        if (pl[i] != nullptr && !pl[i]->IsDead())
        {
            return false;
        }
    }


    return true;
}

bool TestWorld::End()
{
    if (H_goblin->IsDead())
    {
        return true;
    }
    if (Player_All_deed(P_Use))
    {
        cout << "��� ���谡�� ����߽��ϴ�." << endl;


        cout << " ===== ���� ����/��׷� ���� =====" << endl;
        sort(P_Use.begin(), P_Use.end(), [](Creature* a, Creature* b)->bool
            {
                return a->GetAggro_DMG() > b->GetAggro_DMG();
            });
        for (int i = 0; i < P_Use.size(); i++)
        {
            cout << i + 1 << "�� " << P_Use[i]->GetName() << " / �Ѱ� ��/��׷� : " << P_Use[i]->GetAggro_DMG();

        }

        return true;
    }

    return false;
}

void TestWorld::Field()
{
    Battle();
}

vector<Creature*> TestWorld::GetTopAttacker()
{ 
    // ����ִ� �÷��̾�� ������� �������� �����Ͽ� ���� 4���� �÷��̾ ��ȯ
    vector<Creature*> livingPlayers; // ������
    for (auto player : P_Use) 
    {// ����ִ� �÷��̾ üũ�ϰ� ����
        if (!player->IsDead())
        {
            livingPlayers.push_back(player);

        }

      
    }

    sort(livingPlayers.begin(), livingPlayers.end(), [](Creature* a, Creature* b)->bool
        {
            return a->GetAggro_DMG() > b->GetAggro_DMG();
        });


    vector<Creature*> topAttackers; // ��׷ο� ���庤��
    int count = 0;
    for (auto player : livingPlayers)
    {
        topAttackers.push_back(player);
        count++;
        if (count == 4)
            break;
    }

    return topAttackers;
}
