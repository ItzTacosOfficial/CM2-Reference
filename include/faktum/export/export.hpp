#pragma once

#include "faktum/api.hpp"
#include "faktum/object/object.hpp"



class FExport : public FObject {

public:

	FExport();
	FExport(const FExport& other);

	~FExport() override;

	using FObject::operator new;
	using FObject::operator delete;
	void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags = 0);

	FExport& operator=(const FExport& other);

	virtual FClass* GetExportClass() = 0;
	virtual const wchar_t* GetExtension(unsigned int index) = 0;
	virtual unsigned int GetExtensionCount() = 0;
	virtual BOOL ExportObject(FObject* object, const wchar_t* path, FObject* param) = 0;

	static FClass* StaticGetClass();
	static void StaticUnregisterClass();

private:

	static FClass* StaticConstructClassFExport();
	static void StaticInitClassFExport();

	FAK_API static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FExport, 0x28);
