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

	using FObject::operator new;
	using FObject::operator delete;
	static void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags);

	FObject* Clone(const FName&, const FName&, FObject*, int) override;
	void Serialize(FArchive& archive) override;
	virtual void Mutate(float);

	int GetMutationCount() const;
	FMutator* GetMutator(FProperty* property);
	FMutator* GetMutator(int) const;
	FProperty* GetProperty(int) const;
	void RemoveAllMutators();
	BOOL SetMutator(FProperty* property, FMutator* mutator);

	static FClass* StaticGetClass();
	static void StaticInitClass();
	static void StaticUnregisterClass();


	unsigned char unk28[0x10];

private:

	int FindMutation(FProperty* property);

	static FClass* StaticConstructClassFMutable();
	static void StaticInitClassFMutable();

	static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FMutable, 0x38);
