#pragma once

#include "core.hpp"
#include "object.hpp"


class FTexture;

class FAK_IMPORT FExport : public FObject {

public:

	FExport();
	FExport(const FExport& other);

	~FExport() override;

	static void* __cdecl operator new(size_t, FObject*, const FName&, const FName&, unsigned int);

	FExport& operator=(const FExport& other);

	virtual FClass* GetExportClass() = 0;
	virtual const wchar_t* GetExtension(unsigned int index) = 0;
	virtual unsigned int GetExtensionCount() = 0;
	virtual int ExportObject(FObject* object, const wchar_t* path, FObject* unk) = 0;

	static FClass* __cdecl StaticGetClass();
	static void __cdecl StaticUnregisterClass();

private:

	static FClass* __cdecl StaticConstructClassFExport();
	static void __cdecl StaticInitClassFExport();

	static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FExport, 0x28);

class FAK_IMPORT FExportCode : public FExport {

public:

	FExportCode();
	FExportCode(const FExportCode& other);

	~FExportCode() override;

	static void* __cdecl operator new(size_t, FObject*, const FName&, const FName&, unsigned int);

	FExportCode& operator=(const FExportCode& other);

	FClass* GetExportClass() override;
	const wchar_t* GetExtension(unsigned int index) override;
	unsigned int GetExtensionCount() override;
	int ExportObject(FObject* object, const wchar_t* path, FObject* unk) override;

	static void __cdecl StaticConstructor(void* data);
	static FClass* __cdecl StaticGetClass();
	static void __cdecl StaticUnregisterClass();

private:

	static FClass* __cdecl StaticConstructClassFExportCode();
	static void __cdecl StaticInitClassFExportCode();

	static FClass* ms_pClass;

};
//FAK_SIZE_GUARD(FExportCode, 0x28);

class FAK_IMPORT FExportFontF3F : public FExport {

public:

	FExportFontF3F();
	FExportFontF3F(const FExportFontF3F& other);

	~FExportFontF3F() override;

	static void* __cdecl operator new(size_t, FObject*, const FName&, const FName&, unsigned int);

	FExportFontF3F& operator=(const FExportFontF3F& other);

	FClass* GetExportClass() override;
	const wchar_t* GetExtension(unsigned int index) override;
	unsigned int GetExtensionCount() override;
	int ExportObject(FObject* object, const wchar_t* path, FObject* unk) override;

	static void __cdecl StaticConstructor(void* data);
	static FClass* __cdecl StaticGetClass();
	static void __cdecl StaticUnregisterClass();

private:

	static FClass* __cdecl StaticConstructClassFExportFontF3F();
	static void __cdecl StaticInitClassFExportFontF3F();

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

	static void* __cdecl operator new(size_t, FObject*, const FName&, const FName&, unsigned int);

	FExportTextureDDS& operator=(const FExportTextureDDS& other);

	FClass* GetExportClass() override;
	const wchar_t* GetExtension(unsigned int index) override;
	unsigned int GetExtensionCount() override;
	int ExportObject(FObject* object, const wchar_t* path, FObject* unk) override;

	static void __cdecl StaticConstructor(void* data);
	static FClass* __cdecl StaticGetClass();
	static void __cdecl StaticUnregisterClass();

private:

	int BuildHeaderFromImage(FTexture* texture, DDSFILEHEADER* ddsHeader);
	//unsigned int GetDDSFormatFromImage(enum FBitmap::FORMAT format);

	static FClass* __cdecl StaticConstructClassFExportTextureDDS();
	static void __cdecl StaticInitClassFExportTextureDDS();

	static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FExportTextureDDS, 0x28);

class FExportTextureTGA : public FExport {

public:

	FExportTextureTGA();
	FExportTextureTGA(const FExportTextureTGA& other);

	~FExportTextureTGA() override;

	static void* __cdecl operator new(size_t, FObject*, const FName&, const FName&, unsigned int);

	FExportTextureTGA& operator=(const FExportTextureTGA& other);

	FClass* GetExportClass() override;
	const wchar_t* GetExtension(unsigned int index) override;
	unsigned int GetExtensionCount() override;
	int ExportObject(FObject* object, const wchar_t* path, FObject* unk) override;

	static void __cdecl StaticConstructor(void* data);
	static FClass* __cdecl StaticGetClass();
	static void __cdecl StaticUnregisterClass();

private:

	static FClass* __cdecl StaticConstructClassFExportTextureTGA();
	static void __cdecl StaticInitClassFExportTextureTGA();

	static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FExportTextureTGA, 0x28);
