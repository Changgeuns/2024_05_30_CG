#include "pch.h"
#include "ClientPacketHandler.h"
#include "BufferReader.h"
#include "BufferWriter.h"

void ClientPacketHandler::HandlePacket(BYTE* buffer, int32 len)
{
	// TODO : Recv했을 때 패킷 파싱하고 분석
	BufferReader br(buffer, len);

	PacketHeader header;
	br.Peek(&header);

	switch (header.id)
	{
	case 0: // id가 이였다..?
		break;

	case S_TEST:
		Handle_C_TEST(buffer, len);
		break;

	default:
		break;
	}
}

void ClientPacketHandler::Handle_C_TEST(BYTE* buffer, int32 len)
{
	BufferReader br(buffer, len);

	PlayerInfo_Protocol pkt;
	br >> pkt;

	if (pkt.IsValid() == false)
		return;

	vector<BuffData> buffDataes;
	buffDataes.resize(pkt.buffCount);
	for (int i = 0; i < pkt.buffCount; i++)
	{
		br >> buffDataes[i];
	}

	wstring name;
	name.resize(pkt.nameCount);
	for (int i = 0; i < pkt.nameCount; i++)
	{
		br >> name[i];
	}

	wcout.imbue(std::locale("kor"));
	wcout << name << endl;

	cout << "BuffCount : " << buffDataes.size() << endl;
	for (auto buff : buffDataes)
	{
		cout << "BuffId : " << buff.buffId << " / BuffRemain : " << buff.remainTime << endl;
	}

}

void ClientPacketHandler::Handle_C_TEST(BYTE* buffer, int32 len, vector<BuffData> buffs)
{
	BufferReader br(buffer, len);
	int32 t = sizeof(PlayerInfo_Protocol);
	PacketHeader header;
	br >> header;


	int64 id;
	int32 hp;
	int16 atk;
	br >> id >> hp >> atk;

	//vector<BuffData> buffs;
	int16 buffCount = 0;
	br >> buffCount;
	buffs.resize(buffCount);

	for (int32 i = 0; i < buffCount; i++)
	{
		br >> buffs[i].buffId >> buffs[i].remainTime;
	}

	wstring name;
	uint16 nameSize;
	br >> nameSize;
	name.resize(nameSize);

	br.Read((void*)name.data(), nameSize * sizeof(WCHAR));

	cout << "ID : " << id << " HP : " << hp << " ATK : " << atk << endl;
	for (auto& buff : buffs)
	{
		cout << "Buff ID : " << buff.buffId << endl;
		cout << "Buff Remain Time : " << buff.remainTime << endl;
	}

	wcout.imbue(std::locale("kor"));
	wcout << name << endl;

}

shared_ptr<SendBuffer> ClientPacketHandler::Make_S_TEST(int64 id, int32 hp, int16 atk, vector<BuffData> buffs)
{
	shared_ptr<SendBuffer> buf = make_shared<SendBuffer>(1000);
	/*PlayerInfo_Protocol p;
	p.id = id;
	p.hp = hp;
	p.atk = atk;

	BufferWriter bw(buf->Buffer(), buf->Capacity());

	PacketHeader* header = bw.Reserve<PacketHeader>();
	header->id = S_TEST;
	header->size = (sizeof(p) + sizeof(PacketHeader));
	bw << p;

	buf->Ready(bw.WriteSize());*/

	return buf;
}