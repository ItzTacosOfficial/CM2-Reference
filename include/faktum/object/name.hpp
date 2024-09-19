#pragma once

#include "faktum/api.hpp"



template<class T>
class FTArray;
template<class T>
class FTList;
class FString;
class FObject;
class FMutex;


class FName {

public:

	struct Name { // Internal

		int index;
		int refCount;
		char name[0x41];
		Name* lookupNext;

	};
	FAK_SIZE_GUARD(Name, 0x50);

	enum NAME {
		UNNAMED = -1
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

	FAK_API static const FName NONE;


	int index;

protected:

	static int StaticRelease(int index);
	static int StaticAddName(const char* name);
	static int StaticAddRef(int index);

private:

	FName(FObject* object);

	FAK_API static FMutex ms_Mutex;
	FAK_API static FTArray<Name*> ms_aNames;
	FAK_API static Name* ms_apNameHash[0xFFF];
	FAK_API static FTList<int> ms_lnFreeNames;

};
FAK_SIZE_GUARD(FName, 0x4);
