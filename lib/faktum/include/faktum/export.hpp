#pragma once

#include "core.hpp"
#include "object.hpp"


class FTexture;

class FAK_IMPORT FExport : public FObject {

public:

	FExport();
	FExport(const FExport& other);

	~FExport() override;

	using FObject::operator new;
	using FObject::operator delete;
	static void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags);

	FExport& operator=(const FExport& other);

	virtual FClass* GetExportClass() = 0;
	virtual const wchar_t* GetExtension(unsigned int index) = 0;
	virtual unsigned int GetExtensionCount() = 0;
	virtual BOOL ExportObject(FObject* object, const wchar_t* path, FObject* unk) = 0;

	static FClass* StaticGetClass();
	static void StaticUnregisterClass();

private:

	static FClass* StaticConstructClassFExport();
	static void StaticInitClassFExport();

	static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FExport, 0x28);

class FAK_IMPORT FExportCode : public FExport {

public:

	FExportCode();
	FExportCode(const FExportCode& other);

	~FExportCode() override;

	using FObject::operator new;
	using FObject::operator delete;
	static void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags);

	FExportCode& operator=(const FExportCode& other);

	FClass* GetExportClass() override;
	const wchar_t* GetExtension(unsigned int index) override;
	unsigned int GetExtensionCount() override;
	BOOL ExportObject(FObject* object, const wchar_t* path, FObject* unk) override;

	static void StaticConstructor(void* data);
	static FClass* StaticGetClass();
	static void StaticUnregisterClass();

private:

	static FClass* StaticConstructClassFExportCode();
	static void StaticInitClassFExportCode();

	static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FExportCode, 0x28);

class FAK_IMPORT FExportFontF3F : public FExport {

public:

	FExportFontF3F();
	FExportFontF3F(const FExportFontF3F& other);

	~FExportFontF3F() override;

	using FObject::operator new;
	using FObject::operator delete;
	static void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags);

	FExportFontF3F& operator=(const FExportFontF3F& other);

	FClass* GetExportClass() override;
	const wchar_t* GetExtension(unsigned int index) override;
	unsigned int GetExtensionCount() override;
	BOOL ExportObject(FObject* object, const wchar_t* path, FObject* unk) override;

	static void StaticConstructor(void* data);
	static FClass* StaticGetClass();
	static void StaticUnregisterClass();

private:

	static FClass* StaticConstructClassFExportFontF3F();
	static void StaticInitClassFExportFontF3F();

	static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FExportFontF3F, 0x28);

class FExportTextureDDS : public FExport { // TODO Functions

public:

	struct DDSFILEHEADER { // TODO Contents

	};


	FExportTextureDDS();
	FExportTextureDDS(const FExportTextureDDS& other);

	~FExportTextureDDS() override;

	using FObject::operator new;
	using FObject::operator delete;
	static void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags);

	FExportTextureDDS& operator=(const FExportTextureDDS& other);

	FClass* GetExportClass() override;
	const wchar_t* GetExtension(unsigned int index) override;
	unsigned int GetExtensionCount() override;
	BOOL ExportObject(FObject* object, const wchar_t* path, FObject* unk) override;

	static void StaticConstructor(void* data);
	static FClass* StaticGetClass();
	static void StaticUnregisterClass();

private:

	int BuildHeaderFromImage(FTexture* texture, DDSFILEHEADER* ddsHeader);
	//unsigned int GetDDSFormatFromImage(enum FBitmap::FORMAT format);

	static FClass* StaticConstructClassFExportTextureDDS();
	static void StaticInitClassFExportTextureDDS();

	static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FExportTextureDDS, 0x28);

class FExportTextureTGA : public FExport {

public:

	FExportTextureTGA();
	FExportTextureTGA(const FExportTextureTGA& other);

	~FExportTextureTGA() override;

	using FObject::operator new;
	using FObject::operator delete;
	static void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags);

	FExportTextureTGA& operator=(const FExportTextureTGA& other);

	FClass* GetExportClass() override;
	const wchar_t* GetExtension(unsigned int index) override;
	unsigned int GetExtensionCount() override;
	BOOL ExportObject(FObject* object, const wchar_t* path, FObject* unk) override;

	static void StaticConstructor(void* data);
	static FClass* StaticGetClass();
	static void StaticUnregisterClass();

private:

	static FClass* StaticConstructClassFExportTextureTGA();
	static void StaticInitClassFExportTextureTGA();

	static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FExportTextureTGA, 0x28);
