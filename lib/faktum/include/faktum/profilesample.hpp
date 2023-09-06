#pragma once

#include "core.hpp"


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
	int unkC;
	int unk10;
	unsigned int unk14;
	int unk18;
	int unk1C;
	LARGE_INTEGER time;
	int unk28;
	int unk2C;

};
FAK_SIZE_GUARD(FProfileSample, 0x30);
