#pragma once

#include "core.hpp"
#include "field.hpp"


class FAK_IMPORT FStruct : public FField { // TODO Members

public:

	FStruct(const FStruct& other);
	FStruct(const char* name, unsigned int size);

	~FStruct() override;

	FStruct& operator=(const FStruct& other);

	static void* __cdecl operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags);

	FProperty* GetFirstProperty();
	unsigned int GetObjectSize() const;
	FStruct* GetSuperStruct();

	static void __cdecl StaticConstructor(void* data);
	static FClass* __cdecl StaticGetClass();
	static void __cdecl StaticUnregisterClass();


	int objectSize;
	FStruct* superStruct;
	int unk30; // Constructed to 0
	FProperty* property;

protected:

	FStruct();

private:

	static FClass* __cdecl StaticConstructClassFStruct();
	static void __cdecl StaticInitClassFStruct();

	static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FStruct, 0x3C);


FAK_IMPORT FStruct* __cdecl FtRegisterStruct(const char* name, unsigned int size);
