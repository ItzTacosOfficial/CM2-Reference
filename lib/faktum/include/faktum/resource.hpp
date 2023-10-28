#pragma once

#include "core.hpp"
#include "object.hpp"


class FAK_IMPORT FResource : public FObject {

public:

	FResource();
	FResource(const FResource& other);

	~FResource() override;

	FResource& operator=(const FResource& other);

	static void* __cdecl operator new(size_t, FObject*, const FName&, const FName&, unsigned int);

	void PropertyChanged(FProperty* property) override;

	unsigned long long GetResID() const;
	void SetDirty();

	static void __cdecl StaticConstructor(void* data);
	static FClass* __cdecl StaticGetClass();
	static void __cdecl StaticUnregisterClass();


	long long resourceID;

private:

	static FClass* __cdecl StaticConstructClassFResource();
	static void __cdecl StaticInitClassFResource();

	static unsigned long long ms_nNextResID;

	static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FResource, 0x30);
