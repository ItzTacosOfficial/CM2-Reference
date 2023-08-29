#pragma once

#include "core.hpp"
#include "field.hpp"


class FAK_IMPORT FStruct : public FField { // TODO Members

public:

	FStruct(const FStruct& other);
	FStruct(const char*, unsigned int);

	~FStruct() override;

	FStruct& operator=(const FStruct& other);

	static void* __cdecl operator new(unsigned int, FObject*, const FName&, const FName&, unsigned int);

	FProperty* GetFirstProperty();
	unsigned int GetObjectSize() const;
	FStruct* GetSuperStruct();

	static void __cdecl StaticConstructor(void* data);
	static FClass* __cdecl StaticGetClass();
	static void __cdecl StaticUnregisterClass();


	int unk28;
	FClass* baseClass;
	int unk30;
	FProperty* property;

protected:

	FStruct();

private:

	static FClass* __cdecl StaticConstructClassFStruct();
	static void __cdecl StaticInitClassFStruct();

	static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FStruct, 0x3C);
