#pragma once

#include "faktum/api.hpp"
#include "faktum/util/time.hpp"



class FTime;


class FProfileSample {

public:

	FProfileSample(const char* name, const char* function);

	FProfileSample& operator=(const FProfileSample& other);

	unsigned int GetCallCount() const;
	const char* GetFunction() const;
	const char* GetName() const;
	FProfileSample* GetNext() const;
	unsigned int GetParentCount() const;
	FTime GetTime() const;
	void Reset();
	void Start();
	void Stop();


	char* name;
	char* function;
	FProfileSample* next;
	unsigned int callCount;
	unsigned int ongoingCount;
	unsigned int parentCount;
	FTime startTime;
	FTime time;
	int unk28;
	int unk2C;

};
FAK_SIZE_GUARD(FProfileSample, 0x30);
