#pragma once

#include "core.hpp"
#include "object.hpp"


class FAK_IMPORT FImport : public FObject {

public:

	FImport();
	FImport(const FImport& other);

	~FImport() override;

	using FObject::operator new;
	using FObject::operator delete;
	static void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags);

	FImport& operator=(const FImport& other);

	virtual FClass* GetImportClass() = 0;
	virtual FClass* GetOptionsClass();
	virtual const wchar_t* GetExtension(unsigned int index) = 0;
	virtual unsigned int GetExtensionCount() = 0;
	virtual FObject* ImportObject(const wchar_t*, FObject*, const FName&, const FName&, FObject*, FObject*) = 0;

	static FClass* StaticGetClass();
	static void StaticUnregisterClass();

private:

	static FClass* StaticConstructClassFImport();
	static void StaticInitClassFImport();

	static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FImport, 0x28);
