#pragma once

#include "faktum/api.hpp"
#include "export.hpp"



class FExportFontF3F : public FExport {

public:

	FExportFontF3F();
	FExportFontF3F(const FExportFontF3F& other);

	~FExportFontF3F() override;

	using FObject::operator new;
	using FObject::operator delete;
	void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags = 0);

	FExportFontF3F& operator=(const FExportFontF3F& other);

	FClass* GetExportClass() override;
	const wchar_t* GetExtension(unsigned int index) override;
	unsigned int GetExtensionCount() override;
	BOOL ExportObject(FObject* object, const wchar_t* path, FObject* param) override;

	static void StaticConstructor(void* data);
	static FClass* StaticGetClass();
	static void StaticUnregisterClass();

private:

	static FClass* StaticConstructClassFExportFontF3F();
	static void StaticInitClassFExportFontF3F();

	FAK_API static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FExportFontF3F, 0x28);
