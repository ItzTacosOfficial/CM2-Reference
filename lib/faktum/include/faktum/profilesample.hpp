#pragma once

#include "core.hpp"
#include "time.hpp"


class FTime;

class FAK_IMPORT FProfileSample { // TODO Members

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
	int unk10;
	unsigned int parentCount;
	int unk18;
	int unk1C;
	FTime time;
	int unk28;
	int unk2C;

};
FAK_SIZE_GUARD(FProfileSample, 0x30);
