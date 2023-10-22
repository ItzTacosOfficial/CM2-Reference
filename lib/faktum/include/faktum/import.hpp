#pragma once

#include "core.hpp"
#include "object.hpp"


class FAK_IMPORT FImport : public FObject {

public:

	FImport();
	FImport(const FImport& other);

	~FImport() override;

	static void* __cdecl operator new(size_t, FObject*, const FName&, const FName&, unsigned int);

	FImport& operator=(const FImport& other);

	virtual FClass* GetImportClass() = 0;
	virtual FClass* GetOptionsClass();
	virtual const wchar_t* GetExtension(unsigned int index) = 0;
	virtual unsigned int GetExtensionCount() = 0;
	virtual FObject* ImportObject(const wchar_t*, FObject*, const FName&, const FName&, FObject*, FObject*) = 0;

	static FClass* __cdecl StaticGetClass();
	static void __cdecl StaticUnregisterClass();

private:

	static FClass* __cdecl StaticConstructClassFImport();
	static void __cdecl StaticInitClassFImport();

	static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FImport, 0x28);
