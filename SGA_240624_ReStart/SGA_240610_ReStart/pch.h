#pragma once
#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

// �̸������ϵ� ���
// pch.h / pch.cpp ����
// pch.cpp�� �Ӽ� -> c/c++ -> �̸������ϵ���� �����/pch.h
// ������Ʈ �Ӽ� -> c/c++ -> �̸������ϵ���� ���/pch.h


// ����ȭ ������ ��
//������Ʈ �Ӽ�> VC++���丮 >���Ե��͸� ���� > $(projectDir)

#include "./Contents/Creature/Creature.h"
#include "./Contents/Creature/Player.h"
#include "./Contents/Creature/Monster.h"

#include "./Contents/Creature/Knight.h"
#include "./Contents/Creature/Archer.h"
#include "./Contents/Creature/Mage.h"

#include "./Contents/Creature/Goblin.h"
#include "./Contents/Creature/HopGoblin.h"

#include "./Contents/World/World.h"
#include "./Contents/World/TestWorld.h"