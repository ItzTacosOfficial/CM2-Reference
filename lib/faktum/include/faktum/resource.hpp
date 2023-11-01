#pragma once

#include "core.hpp"
#include "object.hpp"


class FAK_IMPORT FResource : public FObject {

public:

	FResource();
	FResource(const FResource& other);

	~FResource() override;

	FResource& operator=(const FResource& other);

	static void* __cdecl operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags);

	void PropertyChanged(FProperty* property) override;

	unsigned long long GetResID() const;
	void SetDirty();

	static void __cdecl StaticConstructor(void* data);
	static FClass* __cdecl StaticGetClass();
	static void __cdecl StaticUnregisterClass();


	unsigned long long resourceID;

private:

	static FClass* __cdecl StaticConstructClassFResource();
	static void __cdecl StaticInitClassFResource();

	static unsigned long long ms_nNextResID;

	static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FResource, 0x30);
