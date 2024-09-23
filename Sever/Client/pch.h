#pragma once

#define WIN32_LEAN_AND_MEAN

#ifdef _DEBUG
#pragma comment(lib, "Debug\\severCore.lib")
#else
#pragma comment(lib, "Release\\severCore.lib")
#endif

#include "CorePch.h"