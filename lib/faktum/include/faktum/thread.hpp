#pragma once

#include "core.hpp"


class FAK_IMPORT FThread { // TODO Members

public:

	using FunctionT = void* (__stdcall*)(void*);

	enum PRIORITY {
		Idle			= THREAD_PRIORITY_IDLE,
		Lowest			= THREAD_PRIORITY_LOWEST,
		BelowNormal		= THREAD_PRIORITY_BELOW_NORMAL,
		Normal			= THREAD_PRIORITY_NORMAL,
		AboveNormal		= THREAD_PRIORITY_ABOVE_NORMAL,
		Highest			= THREAD_PRIORITY_HIGHEST,
		TimeCritical	= THREAD_PRIORITY_TIME_CRITICAL
	};


	FThread();

	~FThread();

	FThread& operator=(const FThread& other);
	operator void*() const;

	void Exit();
	PRIORITY GetPriority();
	unsigned long GetThreadID();
	BOOL Init(FunctionT function, unsigned int, unsigned int stackSize, void*);
	unsigned int Resume();
	BOOL SetPriority(PRIORITY priority);
	unsigned int Suspend();


	int unk0;
	HANDLE unk1;
	FunctionT function;
	HANDLE unk2;

};
FAK_SIZE_GUARD(FThread, 0x10);
