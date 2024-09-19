#pragma once

#include "faktum/api.hpp"



class FThread {

public:

	using FunctionT = void* (__stdcall*)(void*);

	struct FAK_ASSUMED Handle { // Internal

		FThread* self;
		unsigned int flags;
		HANDLE startedEvent;
		HANDLE executeEvent;

	};

	enum PRIORITY {
		PRIO_IDLE			= THREAD_PRIORITY_IDLE,
		PRIO_LOWEST			= THREAD_PRIORITY_LOWEST,
		PRIO_BELOW_NORMAL	= THREAD_PRIORITY_BELOW_NORMAL,
		PRIO_NORMAL			= THREAD_PRIORITY_NORMAL,
		PRIO_ABOVE_NORMAL	= THREAD_PRIORITY_ABOVE_NORMAL,
		PRIO_HIGHEST		= THREAD_PRIORITY_HIGHEST,
		PRIO_TIME_CRITICAL	= THREAD_PRIORITY_TIME_CRITICAL
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
