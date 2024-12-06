#pragma once

#define WIN32_LEAN_AND_MEAN

#ifdef _DEBUG
#pragma comment(lib,"Libs\\ServerCore\\Debug\\ServerCore.lib")
//#pragma comment(lib,"Libs\\ServerCore\\Debug\\TODO.lib")
#else
#pragma comment(lib,"ServerCore\\Release\\ServerCore.lib")
//#pragma comment(lib,"ServerCore\\Release\\TODO.lib")
#endif


#include "CorePch.h"
