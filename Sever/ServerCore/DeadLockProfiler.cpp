#include "pch.h"
#include "DeadLockProfiler.h"

// 
void DeadLockProfiler::PushLock(const char* name)
{
	LockGuard guard(_lock);

	int32 lockId = 0;

	auto findIt = _nameToId.find(name);
	if (findIt == _nameToId.end())
	{
		lockId = static_cast<int32>(_nameToId.size());
		_nameToId[name] = lockId;
		_idToName[lockId] = name;
	}
	else
	{
		lockId = findIt->second;
	}

	// Push �� �ι� ° ����
	// ... ��� �ִ� ���� �־��ٸ�
	if (LLockStack.empty() == false)
	{
		const int32 prevId = LLockStack.top();
		if (lockId != prevId) // lock ���ÿ��� �� ������ �ٸ��ٸ� ����Ŭ �Ǻ��� �ؾ��Ѵ�.
		{
			set<int32>& history = _lockHistory[prevId];
			if (history.find(lockId) == history.end())
			{
				history.insert(lockId);
				CheckCycle();
			}
		}
	}

	LLockStack.push(lockId);
}

void DeadLockProfiler::PopLock(const char* name)
{
	LockGuard guard(_lock);

	if (LLockStack.empty())
		CRASH("MULTIPLE POP");

	int32 lockId = _nameToId[name];
	if (LLockStack.top() != lockId)
		CRASH("UNVAILD POP");

	LLockStack.pop();
}

void DeadLockProfiler::CheckCycle()
{
	// DFS �� �ʱ�ȭ
	const int32 lockCount = static_cast<int32>(_nameToId.size());
	_discoveredOrder = vector<int32>(lockCount, -1);
	_discoveredCount = 0;
	_finished = vector<bool>(lockCount, false);
	_parent = vector<int32>(lockCount, -1);

	for (int32 lockId = 0; lockId < lockCount; lockId++)
	{
		DFS(lockId);
	}

	_discoveredOrder.clear();
	_finished.clear();
	_parent.clear();
}

void DeadLockProfiler::DFS(int32 here)
{
	if (_discoveredOrder[here] != -1)
		return;

	_discoveredOrder[here] = _discoveredCount++;

	auto findIt = _lockHistory.find(here);
	// here���� ������ ������ ����. 
	// 1. ù��° ��
	// 2. ������ Lock
	if (findIt == _lockHistory.end())
	{
		_finished[here] = true;
		return;
	}

	set<int32>& nextSet = findIt->second;
	for (int32 there : nextSet)
	{
		//  ���� �湮���� �ʾ����� �湮
		if (_discoveredOrder[there] == -1)
		{
			_parent[there] = here;
			DFS(there);
			continue;
		}

		// ������ ����
		// here�� there���� ���� �߰ߵǾ��ٸ�, there�� here�� �ļ��̴�.
		if (_discoveredOrder[here] < _discoveredOrder[there])
			continue;

		// �������� �ƴϰ�, DFS(there)�� ���� �������� �ʾҴٸ�, there�� here�� �����̴�. => (������ ����)
		// - there�� here�� �ļ��̿�����, �����̴�.
		if (_finished[there] == false)
		{
			cout << _idToName[here] << " -> " << _idToName[there] << endl;

			int32 now = here;
			while (true)
			{
				cout << _idToName[_parent[now]] << " -> " << _idToName[now] << endl;
				now = _parent[now];
				if (now == there)
					break;
			}

			CRASH("DEADLOCK_DETECTED");
		}
	}

	_finished[here] = true;
}