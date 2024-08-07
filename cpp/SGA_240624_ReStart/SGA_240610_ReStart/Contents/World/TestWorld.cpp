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
        int type = rand() % 3 + 1; // 1: 기사, 2: 궁수, 3: 마법사
        string name = "모험가 " + to_string(i + 1);

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
    H_goblin = make_shared<HopGoblin>("홉 고블린", 3000, 100, 1000); // new HopGoblin("홉 고블린", 3000, 100, 1000);
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
                cout << "기여도/어그로 : " << P_Use[i]->GetAggro_DMG() << endl;
            }
        }

       // 보스가 선빵
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


        cout << counts << " 번째 턴 진행중." << endl;

        if (End())
        {
            system("pause");
            break;
        }
        cout << " ===== 총 어그로 순위 =====" << endl;
        sort(P_Use.begin(), P_Use.end(), [](Creature* a, Creature* b)->bool
            {
                return a->GetAggro_DMG() > b->GetAggro_DMG();
            });
        for (int i = 0; i < P_Use.size(); i++)
        {
            cout << i + 1 << "위 " << P_Use[i]->GetName() << " / 총괄 어그로 : " << P_Use[i]->GetAggro_DMG();
            if (P_Use[i]->IsDead()) cout << "(사망)";
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
        cout << "모든 모험가가 사망했습니다." << endl;


        cout << " ===== 최종 딜량/어그로 집계 =====" << endl;
        sort(P_Use.begin(), P_Use.end(), [](Creature* a, Creature* b)->bool
            {
                return a->GetAggro_DMG() > b->GetAggro_DMG();
            });
        for (int i = 0; i < P_Use.size(); i++)
        {
            cout << i + 1 << "위 " << P_Use[i]->GetName() << " / 총괄 딜/어그로 : " << P_Use[i]->GetAggro_DMG();

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
    // 살아있는 플레이어만을 대상으로 내림차순 정렬하여 상위 4명의 플레이어를 반환
    vector<Creature*> livingPlayers; // 생존자
    for (auto player : P_Use) 
    {// 살아있는 플레이어를 체크하고 저장
        if (!player->IsDead())
        {
            livingPlayers.push_back(player);

        }

      
    }

    sort(livingPlayers.begin(), livingPlayers.end(), [](Creature* a, Creature* b)->bool
        {
            return a->GetAggro_DMG() > b->GetAggro_DMG();
        });


    vector<Creature*> topAttackers; // 어그로용 저장벡터
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
