#pragma once

#include "core.hpp"
#include "object.hpp"


class FMutator;
class FProperty;

class FAK_IMPORT FMutable : public FObject { // TODO Undocumented

public:

	FMutable();
	FMutable(const FMutable& other);

	~FMutable() override;

	FMutable& operator=(const FMutable& other);

	static void* __cdecl operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags);

	FObject* Clone(const FName&, const FName&, FObject*, int) override;
	void Serialize(FArchive& archive) override;
	virtual void Mutate(float);

	int GetMutationCount() const;
	FMutator* GetMutator(FProperty* property);
	FMutator* GetMutator(int) const;
	FProperty* GetProperty(int) const;
	void RemoveAllMutators();
	BOOL SetMutator(FProperty* property, FMutator* mutator);

	static FClass* __cdecl StaticGetClass();
	static void __cdecl StaticInitClass();
	static void __cdecl StaticUnregisterClass();


	unsigned char unk28[0x10];

private:

	int FindMutation(FProperty* property);

	static FClass* __cdecl StaticConstructClassFMutable();
	static void __cdecl StaticInitClassFMutable();

	static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FMutable, 0x38);
