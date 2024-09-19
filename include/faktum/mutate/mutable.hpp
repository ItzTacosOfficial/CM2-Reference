#pragma once

#include "faktum/api.hpp"
#include "faktum/object/object.hpp"
#include "faktum/util/array.hpp"



class FMutator;
class FProperty;


class FMutable : public FObject {

public:

	struct FAK_ASSUMED Mutation {

		FMutator* mutator;
		FProperty* property;

	};
	FAK_SIZE_GUARD(Mutation, 0x8);


	FMutable();
	FMutable(const FMutable& other);

	~FMutable() override;

	FMutable& operator=(const FMutable& other);

	using FObject::operator new;
	using FObject::operator delete;
	void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags = 0);

	FObject* Clone(const FName& object, const FName& storage, FObject*, int) override;
	void Serialize(FArchive& archive) override;
	virtual void Mutate(float);

	int GetMutationCount() const;
	FMutator* GetMutator(FProperty* property);
	FMutator* GetMutator(int index) const;
	FProperty* GetProperty(int index) const;
	void RemoveAllMutators();
	BOOL SetMutator(FProperty* property, FMutator* mutator);

	static FClass* StaticGetClass();
	static void StaticInitClass();
	static void StaticUnregisterClass();


	FTArray<Mutation> mutations;

private:

	int FindMutation(FProperty* property);

	static FClass* StaticConstructClassFMutable();
	static void StaticInitClassFMutable();

	FAK_API static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FMutable, 0x38);
