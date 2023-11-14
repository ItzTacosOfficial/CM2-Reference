#pragma once

#include "faktum/api.hpp"
#include "object.hpp"


class FField : public FObject { // TODO Members

public:

	FField(const FField& other);
	FField(const char* name);

	~FField() override;

	FField& operator=(const FField& other);

	using FObject::operator new;
	using FObject::operator delete;
	static void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags);

	static void StaticConstructor(void* data);
	static FClass* StaticGetClass();
	static void StaticUnregisterClass();


	int unk24;

protected:

	FField();

private:

	static FClass* StaticConstructClassFField();
	static void StaticInitClassFField();

	FAK_API static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FField, 0x2C);
