#pragma once

#include "faktum/api.hpp"
#include "export.hpp"



class FExportTextureTGA : public FExport {

public:

	FExportTextureTGA();
	FExportTextureTGA(const FExportTextureTGA& other);

	~FExportTextureTGA() override;

	using FObject::operator new;
	using FObject::operator delete;
	void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags = 0);

	FExportTextureTGA& operator=(const FExportTextureTGA& other);

	FClass* GetExportClass() override;
	const wchar_t* GetExtension(unsigned int index) override;
	unsigned int GetExtensionCount() override;
	BOOL ExportObject(FObject* object, const wchar_t* path, FObject* param) override;

	static void StaticConstructor(void* data);
	static FClass* StaticGetClass();
	static void StaticUnregisterClass();

private:

	static FClass* StaticConstructClassFExportTextureTGA();
	static void StaticInitClassFExportTextureTGA();

	FAK_API static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FExportTextureTGA, 0x28);
