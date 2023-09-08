#pragma once

#include "core.hpp"
#include "struct.hpp"


class FAK_IMPORT FClass : public FStruct { // TODO Members

public:

	using StaticConstructorT = void (__cdecl*)(void*);
	using RegisterClassT = void (__cdecl*)();


	FClass(const FClass& other);
	FClass(const char* objectName, int, StaticConstructorT staticConstructor, RegisterClassT registerClass);

	~FClass() override;

	FClass& operator=(const FClass&);

	static void* __cdecl operator new(size_t, FObject*, const FName&, const FName&, unsigned int);

	virtual void Register();

	FClass* GetSuperClass();
	int IsDerivedFrom(FClass*);
	void SetSuperClass(FClass*);

	static void __cdecl StaticDumpClasses(FTextDevice*);
	static FClass* __cdecl StaticGetClass();
	static void __cdecl StaticUnregisterClass();


	StaticConstructorT staticConstructorFunction;
	RegisterClassT registerClassFunction;
	int unk40[2];

protected:

	FClass();

private:

	void Dump(FTextDevice* textDevice, unsigned int&, unsigned int);

	static FClass* __cdecl StaticConstructClassFClass();
	static void __cdecl StaticInitClassFClass();

	static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FClass, 0x4C);
