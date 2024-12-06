#include "pch.h"
#include "GameSession.h"
#include "GameSessionManager.h"
#include "BufferWriter.h"
#include "ServerPacketHandler.h"

GameSession::GameSession()
{

}

GameSession::~GameSession()
{
}

void GameSession::OnConnected()
{

	/////////////////
	// Packet 제작 //
	/////////////////

	PKT_S_TEST_WRITE pkt_write(1234, 10, 5);
	auto buffList = pkt_write.ReserveBuffList(2);
	auto wCharList = pkt_write.Reserve_WCHARList(10);
	
	//buff
	{
		buffList[0] = { 241203, 6 };
		auto victimList0 = pkt_write.ReservevictimList(&buffList[0], 2);
		{
			victimList0[0] = 100;
			victimList0[1] = 101;
		}
		

		buffList[1] = { 240528,23 };
		auto victimList1 = pkt_write.ReservevictimList(&buffList[1], 4);
		{
			victimList1[0] = 614;
			victimList1[1] = 622;
			victimList1[2] = 1109;
			victimList1[3] = 1211;
		}
	}

	//name
	{
		wCharList[0] = L'C';
		wCharList[1] = L'h';
		wCharList[2] = L'a';
		wCharList[3] = L'n';
		wCharList[4] = L'g';
		wCharList[5] = L'G';
		wCharList[6] = L'e';
		wCharList[7] = L'u';
		wCharList[8] = L'n';
		wCharList[9] = L'\0';
	}
	
	G_GameSessionManager->BroadCast(pkt_write.Ready());

	G_GameSessionManager->Add(static_pointer_cast<GameSession>(shared_from_this()));
}


void GameSession::OnSend(int32 len)
{
	cout << "Send 성공 : " << len << endl;
}

int32 GameSession::OnRecvPacket(BYTE* buffer, int32 len)
{
	PacketHeader header = *((PacketHeader*)buffer);

	cout << "Paket ID : " << header.id << "  Size : " << header.size << endl;

	ServerPacketHandler::HandlePacket(buffer, len);

	return len;
}

void GameSession::DisConnected()
{
	G_GameSessionManager->Remove(static_pointer_cast<GameSession>(shared_from_this()));
	cout << "DisConnected" << endl;
}