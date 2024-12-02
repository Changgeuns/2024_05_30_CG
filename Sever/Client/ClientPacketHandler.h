#pragma once

// 규약
enum PacketID
{
	NONE,
	S_TEST = 1,
};

enum BuffID
{
	BUFF_NONE,
	BUFF_LOVE = 1,
	BUFF_ANESTHESIA = 2
};

// 패킷 직렬화란...
//

struct BuffData
{
	uint32 buffId;
	float remainTime;
};

#pragma pack(1)
struct PlayerInfo_Protocol
{
	// 공용헤더
	PacketHeader header; // 4
	// id 고정(S_TEST)

	int64 id; // 8
	int32 hp; // 4
	int16 atk; // 2

	uint32 buffOffset;
	uint32 buffCount;

	uint32 nameOffset;
	uint32 nameCount;

	bool IsValid()
	{
		uint32 size = 0;
		size += sizeof(PlayerInfo_Protocol);
		size += buffCount * sizeof(BuffData);
		size += nameCount * sizeof(WCHAR);

		// 너가 기입한 크기가 실제 패킷크기랑 동일.
		if (size != header.size)
			return false;

		// 흘러넘치게 들어왔다? 뭔가 이상함
		if (nameOffset + nameCount * sizeof(WCHAR) > header.size)
			return false;

		return true;

	}
};
#pragma pack()

class ClientPacketHandler
{
public:
	// Packet형태로 들어왔을 때 => Recv했을  처리 방법
	static void HandlePacket(BYTE* buffer, int32 len);

	static void Handle_C_TEST(BYTE* buffer, int32 len);
	static void Handle_C_TEST(BYTE* buffer, int32 len, vector<BuffData> buffs);

	// Packet형태로 SendBuffer 만들기
	static shared_ptr<SendBuffer> Make_S_TEST(int64 id, int32 hp, int16 atk, vector<BuffData> buffs);
};

