#pragma once

#include "core.hpp"
#include "object.hpp"


class FAK_IMPORT FField : public FObject { // TODO Members

public:

	FField(const FField& other);
	FField(const char*);

	~FField() override;

	FField& operator=(const FField& other);

	static void* __cdecl operator new(size_t, FObject*, const FName&, const FName&, unsigned int);

	static void __cdecl StaticConstructor(void* data);
	static FClass* __cdecl StaticGetClass();
	static void __cdecl StaticUnregisterClass();


	int unk24;

protected:

	FField();

private:

	static FClass* __cdecl StaticConstructClassFField();
	static void __cdecl StaticInitClassFField();

	static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FField, 0x2C);
