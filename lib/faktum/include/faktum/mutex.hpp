#pragma once

#include "core.hpp"


class FAK_IMPORT FMutex { // TODO Critical section

public:

	FMutex(const char* name);

	~FMutex();

	FMutex& operator=(const FMutex& other);

	void Enter();
	void Leave();


	BOOL useCriticalSection;
	CRITICAL_SECTION criticalSection;
	HANDLE handle;

};
FAK_SIZE_GUARD(FMutex, 0x20);
