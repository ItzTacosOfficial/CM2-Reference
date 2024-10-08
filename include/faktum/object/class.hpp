#pragma once

#include "faktum/api.hpp"
#include "struct.hpp"



class FClass : public FStruct {

public:

	using StaticConstructorT = void (__cdecl*)(void*);
	using RegisterClassT = void (__cdecl*)();


	FClass(const FClass& other);
	FClass(const char* object, int size, StaticConstructorT staticConstructor, RegisterClassT registerClass);

	~FClass() override;

	FClass& operator=(const FClass& other);

	using FObject::operator new;
	using FObject::operator delete;
	void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags = 0);

	void Register() override;

	FClass* GetSuperClass();
	BOOL IsDerivedFrom(FClass* fclass);
	void SetSuperClass(FClass* fclass);

	static void StaticDumpClasses(FTextDevice* textDevice);
	static FClass* StaticGetClass();
	static void StaticUnregisterClass();


	StaticConstructorT staticConstructorFunction;
	RegisterClassT registerClassFunction;
	int unk40;
	int unk44;

protected:

	FClass();

private:

	void Dump(FTextDevice* textDevice, unsigned int& count, unsigned int spacing);

	static FClass* StaticConstructClassFClass();
	static void StaticInitClassFClass();

	FAK_API static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FClass, 0x4C);
