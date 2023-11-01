#pragma once

#include "core.hpp"


template<class T>
class FTArray;
class FString;
class FObject;
class FMutex;

class FAK_IMPORT FName { // static members

public:

	struct Name { // Internal

		int index;
		int refCount;
		char name[0x41];
		Name* lookupNext;

	};
	FAK_SIZE_GUARD(Name, 0x50);

	enum NAME {
		Unnamed = -1
	};


	FName();
	FName(const FName& other);
	FName(const char* name);
	FName(NAME name);

	~FName();

	FName& operator=(const FName& other);
	BOOL operator==(const FName& other) const;
	BOOL operator!=(const FName& other) const;
	operator const char*() const;

	int GetIndex() const;
	FString GetString() const;

	static void StaticExit();
	static FName StaticFindName(const char* name);
	static int StaticGetNameCount();
	static void StaticInit();

	static const FName NONE;


	int index;

protected:

	static int StaticRelease(int index);
	static int StaticAddName(const char* name);
	static int StaticAddRef(int index);

private:

	FName(FObject* object);

	static FMutex ms_Mutex;
	static FTArray<Name*> ms_aNames;
	static Name* ms_apNameHash[0xFFF];
	//static FTList<int> ms_lnFreeNames;

};
FAK_SIZE_GUARD(FName, 0x4);
