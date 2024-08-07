#pragma once
class TestWorld
{
public:
	TestWorld();
	~TestWorld();


	void Init(); // √ ±‚»≠
	//bool End(int P_size);
	void SpawnUse();
	void SpawnH_gb();

	void Battle();
	bool Player_All_deed(vector<Creature*> pl);
	bool End();
	void Field();
private:
	shared_ptr<Creature> H_goblin;
	vector<shared_ptr<Creature>> P_Use;
	vector<Creature*> GetTopAttacker();

};

