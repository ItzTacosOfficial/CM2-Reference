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

	~FText() override;

	FText& operator=(const FText& other);
	const FString& operator=(const FString& str);
	const FString& operator=(const wchar_t* str);
	const FString& operator=(wchar_t c);

	using FObject::operator new;
	using FObject::operator delete;
	static void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags);

	void Serialize(FArchive& archive) override;

	static void StaticConstructor(void* data);
	static FClass* StaticGetClass();
	static void StaticInitClass();
	static FText* StaticLoadSafe(const char* storageName, const char* object, LANGUAGE language);
	static void StaticUnregisterClass();

private:

	static FClass* StaticConstructClassFText();
	static void StaticInitClassFText();

	static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FText, 0x30);
