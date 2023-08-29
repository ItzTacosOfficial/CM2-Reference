#pragma once

#include "core.hpp"


class FObject;
class FString;
class FMutex;

class FAK_IMPORT FName { // TODO Members, static members

public:

	struct Name {}; // TODO Contents

	enum NAME {}; // TODO Contents


	FName(const FName& other);
	FName(const char* name);
	FName(NAME name);
	FName();

	~FName();

	FName& operator=(const FName& other);
	int operator==(const FName& other) const;
	int operator!=(const FName& other) const;
	operator const char*() const;

	int GetIndex() const;
	FString GetString() const;

	static void __cdecl StaticExit();
	static FName __cdecl StaticFindName(const char* name);
	static int __cdecl StaticGetNameCount();
	static void __cdecl StaticInit();


	static const FName NONE;

	int unk0;

protected:

	static int __cdecl StaticRelease(int index);
	static int __cdecl StaticAddName(const char* name);
	static int __cdecl StaticAddRef(int index);

private:

	FName(FObject* object);


	static FMutex ms_Mutex;
	//static FTArray<struct Name*> ms_aNames;
	static struct Name** ms_apNameHash;
	//static FTList<int> ms_lnFreeNames;

};
FAK_SIZE_GUARD(FName, 0x4);
