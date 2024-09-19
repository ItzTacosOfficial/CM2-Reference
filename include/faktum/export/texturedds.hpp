#pragma once

#include "faktum/api.hpp"
#include "export.hpp"



class FTexture;


class FExportTextureDDS : public FExport {

public:

	struct DDSFILEHEADER {};


	FExportTextureDDS();
	FExportTextureDDS(const FExportTextureDDS& other);

	~FExportTextureDDS() override;

	using FObject::operator new;
	using FObject::operator delete;
	void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags = 0);

	FExportTextureDDS& operator=(const FExportTextureDDS& other);

	FClass* GetExportClass() override;
	const wchar_t* GetExtension(unsigned int index) override;
	unsigned int GetExtensionCount() override;
	BOOL ExportObject(FObject* object, const wchar_t* path, FObject* param) override;

	static void StaticConstructor(void* data);
	static FClass* StaticGetClass();
	static void StaticUnregisterClass();

private:

	int BuildHeaderFromImage(FTexture* texture, DDSFILEHEADER* ddsHeader);
	//unsigned int GetDDSFormatFromImage(enum FBitmap::FORMAT format);

	static FClass* StaticConstructClassFExportTextureDDS();
	static void StaticInitClassFExportTextureDDS();

	FAK_API static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FExportTextureDDS, 0x28);