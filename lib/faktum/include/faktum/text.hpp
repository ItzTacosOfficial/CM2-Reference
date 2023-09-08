#pragma once

#include "core.hpp"
#include "object.hpp"
#include "string.hpp"


class FAK_IMPORT FText : public FObject, public FString {

public:

	FText();
	FText(const FText& other);
	FText(const FString& str);
	FText(unsigned int size, const wchar_t* data);
	FText(const wchar_t* str);
	FText(wchar_t c, unsigned int count);

	virtual ~FText();

	FText& operator=(const FText& other);
	const FString& operator=(const FString& str);
	const FString& operator=(const wchar_t* str);
	const FString& operator=(wchar_t c);

	static void* __cdecl operator new(size_t, FObject*, const FName&, const FName&, unsigned int);

	virtual void Serialize(FArchive& arc) override;

	static void __cdecl StaticConstructor(void* data);
	static FClass* __cdecl StaticGetClass();
	static void __cdecl StaticInitClass();
	static FText* __cdecl StaticLoadSafe(const char*, const char*, LANGUAGE);
	static void __cdecl StaticUnregisterClass();

private:

	static FClass* __cdecl StaticConstructClassFText();
	static void __cdecl StaticInitClassFText();

	static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FText, 0x30);
