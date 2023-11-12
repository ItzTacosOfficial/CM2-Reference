#pragma once

#include "faktum/api.hpp"


class FAK_API FMutex { // TODO Critical section

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
