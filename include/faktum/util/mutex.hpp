#pragma once

#include "faktum/api.hpp"



class FMutex {

public:

	FMutex(const char* name = nullptr);

	~FMutex();

	FMutex& operator=(const FMutex& other);

	void Enter();
	void Leave();


	BOOL useCriticalSection;
	CRITICAL_SECTION criticalSection;
	HANDLE handle;

};
FAK_SIZE_GUARD(FMutex, 0x20);
