#pragma once

#include "faktum/api.hpp"


class FThread {

public:

	using FunctionT = void* (__stdcall*)(void*);

	struct FAK_ASSUMED Handle { // Internal

		FThread* self;
		int flags;
		HANDLE startedEvent;
		HANDLE executeEvent;

	};

	enum PRIORITY {
		IDLE			= THREAD_PRIORITY_IDLE,
		LOWEST			= THREAD_PRIORITY_LOWEST,
		BELOW_NORMAL	= THREAD_PRIORITY_BELOW_NORMAL,
		NORMAL			= THREAD_PRIORITY_NORMAL,
		ABOVE_NORMAL	= THREAD_PRIORITY_ABOVE_NORMAL,
		HIGHEST			= THREAD_PRIORITY_HIGHEST,
		TIME_CRITICAL	= THREAD_PRIORITY_TIME_CRITICAL
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
