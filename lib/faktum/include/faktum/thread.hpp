#pragma once

#include "core.hpp"


class FAK_IMPORT FThread {

public:

	using FunctionT = void* (__stdcall*)(void*);

	struct FAK_ASSUMED Work { // Internal

		FThread* self;
		int flags;
		HANDLE startedEvent;
		HANDLE executeEvent;

	};

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
	BOOL Init(FunctionT function, unsigned int flags, unsigned int stackSize, void* userData);
	unsigned int Resume();
	BOOL SetPriority(PRIORITY priority);
	unsigned int Suspend();


	unsigned long threadID;
	HANDLE handle;
	FunctionT function;
	void* userData;

};
FAK_SIZE_GUARD(FThread, 0x10);
