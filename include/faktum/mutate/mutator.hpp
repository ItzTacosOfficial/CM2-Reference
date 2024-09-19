#pragma once

#include "faktum/api.hpp"
#include "faktum/object/object.hpp"



class FMutator : public FObject {

public:

	FMutator();
	FMutator(const FMutator& other);

	~FMutator() override;

	FMutator& operator=(const FMutator& other);

	void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags = 0);

	virtual BOOL Mutate(FObject*, FProperty*, float) = 0;

	static FClass* StaticGetClass();
	static void StaticInitClass();
	static void StaticUnregisterClass();

private:

	static FClass* StaticConstructClassFMutator();
	static void StaticInitClassFMutator();

	FAK_API static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FMutator, 0x28);
