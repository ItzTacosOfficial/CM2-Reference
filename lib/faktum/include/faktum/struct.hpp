#pragma once

#include "core.hpp"
#include "field.hpp"


class FAK_IMPORT FStruct : public FField { // TODO Members

public:

	FStruct(const FStruct& other);
	FStruct(const char* name, unsigned int size);

	~FStruct() override;

	FStruct& operator=(const FStruct& other);

	static void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags);

	FProperty* GetFirstProperty();
	unsigned int GetObjectSize() const;
	FStruct* GetSuperStruct();

	static void StaticConstructor(void* data);
	static FClass* StaticGetClass();
	static void StaticUnregisterClass();


	int objectSize;
	FStruct* superStruct;
	int unk30; // Constructed to 0
	FProperty* property;

protected:

	FStruct();

private:

	static FClass* StaticConstructClassFStruct();
	static void StaticInitClassFStruct();

	static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FStruct, 0x3C);


FAK_IMPORT FStruct* FtRegisterStruct(const char* name, unsigned int size);
