﻿#pragma once

#include "BufferWriter.h"

enum PacketID
{
	NONE,
	S_TEST = 1,
};

/////////////////
// Packet List //
/////////////////
template<typename T, typename C>
class PacketList_Iterator
{
public:
	PacketList_Iterator(C& container, uint16 index) : _container(container), _index(index) {}

	bool			operator!=(const PacketList_Iterator& other) { return _index != other._index; }
	const T& operator*() const { return _container[_index]; }
	T& operator*() { return _container[_index]; }
	T* operator->() { return &_container[_index]; }
	PacketList_Iterator& operator++() { _index++; return *this; }
	PacketList_Iterator operator++(int32) { PacketList_Iterator temp = *this; _index++; return temp; }

private:
	C& _container;
	uint16		_index;

};

template<typename T>
class PacketList
{
public:
	PacketList() : _data(nullptr), _count(0) {}
	PacketList(T* data, uint16 count) : _data(data), _count(count) {}

	T& operator[](uint16 index)
	{
		ASSERT_CRASH(index < _count);
		return _data[index];
	}

	uint16 size() { return _count; }
	PacketList_Iterator<T, PacketList<T>> begin() { return PacketList_Iterator<T, PacketList<T>>(*this, 0); }
	PacketList_Iterator<T, PacketList<T>> end() { return PacketList_Iterator<T, PacketList<T>>(*this, _count); }
private:
	T* _data;
	uint16	_count;

};

enum BuffID
{
	BUFF_NONE,
	BUFF_LOVE = 1,
	BUFF_ANESTHESIA = 2
};

struct BuffData
{
	uint32 buffId;
	float remainTime;

	//vector<int32> victims;
	uint32 victimOffset;
	uint32 victimCount;
};

#pragma pack(1)
struct PlayerInfo_Packet
{
	// 공용헤더
	PacketHeader header; // 4
	// id 고정(S_TEST)

	int64 id; // 8
	int32 hp; // 4
	int16 atk; // 2

	uint32 buffOffset;
	uint32 buffCount;

	uint32 wCharOffset;
	uint32 wCharCount;

	bool IsValid()
	{
		uint32 size = 0;
		size += sizeof(PlayerInfo_Packet);
		size += buffCount * sizeof(BuffData);
		size += wCharCount * sizeof(WCHAR);

		// 너가 기입한 크기가 실제 패킷크기랑 동일.
		if (size != header.size)
			return false;

		// 흘러넘치게 들어왔다? 뭔가 이상함
		if (wCharOffset + wCharCount * sizeof(WCHAR) > header.size)
			return false;

		return true;

	}
};
#pragma pack()

class ServerPacketHandler
{
public:
	static void HandlePacket(BYTE* buffer, int32 len);

	static void Handle_S_TEST(BYTE* buffer, int32 len);

	
};

class PKT_S_TEST_WRITE
{
public:
	PKT_S_TEST_WRITE(int64 id, int32 hp, int16 atk)
	{
		_sendBuffer = make_shared<SendBuffer>(1000);
		_bw = BufferWriter(_sendBuffer->Buffer(), _sendBuffer->Capacity());

		_pkt = _bw.Reserve<PlayerInfo_Packet>();
		_pkt->header.id = S_TEST;
		_pkt->header.size = 0; // TODO
		_pkt->id = id;
		_pkt->hp = hp;
		_pkt->atk = atk;
		_pkt->buffCount = 0;
		_pkt->buffOffset = 0;
		_pkt->wCharCount = 0;
		_pkt->wCharOffset = 0;

	}

	PacketList<BuffData> ReserveBuffList(uint16 buffCount)
	{
		BuffData* buffListBegin = _bw.Reserve<BuffData>(buffCount);
		_pkt->buffOffset = (uint64)buffListBegin - (uint64)_pkt;
		_pkt->buffCount = buffCount;
		return PacketList<BuffData>(buffListBegin, buffCount);
	}

	PacketList<int32> ReservevictimList(BuffData* buff, uint16 victimCount)
	{
		int32* victimBegin = _bw.Reserve<int32>(victimCount);
		buff->victimOffset = (uint64)victimBegin - (uint64)_pkt;
		buff->victimCount = victimCount;
		return PacketList<int32>(victimBegin, victimCount);
		
	}

	PacketList<WCHAR> Reserve_WCHARList(uint16 wcharCount)
	{
		WCHAR* strBigin = _bw.Reserve<WCHAR>(wcharCount);
		_pkt->wCharOffset = (uint16)strBigin - (uint16)_pkt;
		_pkt->wCharCount = wcharCount;
		return PacketList<WCHAR>(strBigin, wcharCount);
	}

	shared_ptr<SendBuffer> Ready()
	{
		_pkt->header.size = _bw.WriteSize();
		_sendBuffer->Ready(_bw.WriteSize());

		return _sendBuffer;
	}

private:
	PlayerInfo_Packet* _pkt = nullptr;
	shared_ptr<SendBuffer> _sendBuffer;
	BufferWriter _bw;

};