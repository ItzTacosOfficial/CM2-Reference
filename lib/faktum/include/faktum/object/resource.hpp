#pragma once

#include "faktum/api.hpp"
#include "object.hpp"


class FResource : public FObject {

public:

	FResource();
	FResource(const FResource& other);

	~FResource() override;

	FResource& operator=(const FResource& other);

	using FObject::operator new;
	using FObject::operator delete;
	static void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags = 0);

	void PropertyChanged(FProperty* property) override;

	unsigned long long GetResID() const;
	void SetDirty();

	static void StaticConstructor(void* data);
	static FClass* StaticGetClass();
	static void StaticUnregisterClass();


	unsigned long long resourceID;

private:

	static FClass* StaticConstructClassFResource();
	static void StaticInitClassFResource();

	FAK_API static unsigned long long ms_nNextResID;

	FAK_API static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FResource, 0x30);
