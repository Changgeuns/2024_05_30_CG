#include "pch.h"
#include "AlkaScene.h"

#include "Objects/Alka/AlkaPlayer.h"

AlkaScene::AlkaScene()
{
	_playerBar = make_shared<AlkaPlayer>();
}

AlkaScene::~AlkaScene()
{
}

void AlkaScene::Update()
{
	_playerBar->Update();
}

void AlkaScene::Render(HDC hdc)
{
	_playerBar->Render(hdc);
}
