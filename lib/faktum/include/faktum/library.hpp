#pragma once

#include "core.hpp"


class FAK_IMPORT FLibrary { // TODO Members

public:

	using FunctionT = void (__cdecl*)(void);


	FLibrary(FunctionT init, FunctionT exit);

	FLibrary& operator=(const FLibrary& other);

	void ExitLibrary();
	FLibrary* GetNext();
	void InitLibrary();
	void Initialize(int unk4);
	BOOL IsInitialized();
	void SetModuleHandle(void* moduleHandle);
	void SetNext(FLibrary* next);


	void* moduleHandle;
	int unk4; // Constructed to 0
	FunctionT initFunction;
	FunctionT exitFunction;
	FLibrary* next;

};
FAK_SIZE_GUARD(FLibrary, 0x14);


FAK_IMPORT void __cdecl FtAttachLibrary(FLibrary*);
FAK_IMPORT void __cdecl FtDetachLibrary(FLibrary*);
