#include "pch.h"
#include "AccountManager.h"
#include "UserManager.h"

AccountManager* AccountManager::_instance = nullptr;

void AccountManager::Login()
{
	WRITE_LOCK;

	// Login 성공, ,..?
	// -> 어떤 User인지 확인
	cout << "Login 시도" << endl;
	this_thread::sleep_for(100ms);

	// Dead Lock 유발
	User* user = UserManager::GetInstance()->GetUser(10);

	// User확인 성공 및 클라이언트에게 메시지

	return;
}
