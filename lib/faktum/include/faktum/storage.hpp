#pragma once

#include "core.hpp"
#include "object.hpp"
#include "archive.hpp"
#include "string.hpp"


class FCodec;
class FObject;
class FName;
class FTextDevice;
class FClass;
class FMutex;

class FAK_IMPORT FStorage : public FObject { // TODO Members, static members, functions

public:

	class Archive : public FArchive { // TODO Verify

	public:

		int Close() override;
		unsigned int Read(void*, unsigned int) override;
		unsigned int Write(const void*, unsigned int) override;
		void Flush() override;
		int Tell() override;
		void ReadName(FName& name) override;
		void WriteName(const FName& name) override;
		FObject* ReadObject() override;
		void WriteObject(const FObject* object) override;


		FArchive* fileArchive;
		FStorage* storage;
		FCodec* codec;
		int unk14;
		int unk18;

	};

	struct FAK_ASSUMED Name {

		char* str;
		unsigned int length;

	};

	struct HeaderV3 { // TODO Verify offsets types

		unsigned int magic;
		unsigned int version;
		unsigned int unk8;
		unsigned int unkC;
		unsigned int objectsCount;
		BOOL zipObjects;
		unsigned long long objectsOffset;
		unsigned int objNamesCount;
		BOOL zipNames;
		unsigned long long objNamesOffset;
		unsigned int classNamesCount;
		unsigned int unk34;
		unsigned long long classNamesOffset;

	};

	struct FAK_ASSUMED HeaderV2 { // TODO Contents

		unsigned int magic;
		unsigned int version;
		unsigned int unk8;
		unsigned int unkC;
		unsigned int unk10;
		unsigned int unk14;
		unsigned long long unk18;
		unsigned int unk20;
		BOOL zip;
		unsigned long long unk28;
		unsigned int unk30;
		unsigned int unk34;
		unsigned long long unk38;
		unsigned long long unk40;

	};

	struct FAK_ASSUMED ObjectInfoV3 { // TODO Contents

		unsigned int nameIndex;
		unsigned int classIndex;
		unsigned int unk8;
		unsigned int unkC;
		unsigned int unk10;
		unsigned int unused14;
		unsigned long long dataOffset;
		unsigned long long dataSize;
		FObject::LANGUAGE language;
		unsigned int unused2C;

	};


	FStorage(const FStorage& other);
	FStorage();

	virtual ~FStorage();

	static void* __cdecl operator new(size_t, FObject*, const FName&, const FName&, unsigned int);

	FStorage& operator=(const FStorage& other);

	virtual void Dump(FTextDevice* textDevice);

	int DeleteObject(const char*, unsigned int);
	void Empty();
	int FindObject(const char*, FClass*, unsigned int);
	const wchar_t* GetFilePath() const;
	const FClass* GetNameCodecClass() const;
	const char* GetObjectClass(int id) const;
	const FClass* GetObjectCodecClass() const;
	int GetObjectCount() const;
	const char* GetObjectGroup(int id) const;
	unsigned int GetObjectLanguage(int id) const;
	FString GetObjectMD5(int id) const;
	const char* GetObjectName(int id) const;
	unsigned int GetStorageFlags() const;
	int Load(const wchar_t* path);
	FObject* LoadObject(const char*, FClass*, unsigned int);
	int ReloadObject(FObject* object);
	int RenameObject(int id, const char* name);
	void Revert();
	int Save(const wchar_t* path);
	void SetFilePath(const wchar_t* path);
	void SetNameCodec(FClass* fclass);
	void SetObjectCodec(FClass* fclass);
	void SetObjectGroup(int, const FName&);
	void SetStorageFlags(unsigned int flags);

	static int __cdecl StaticAddSearchPattern(const wchar_t*);
	static FClass* __cdecl StaticClassFromNameTableCodec(int);
	static void __cdecl StaticConstructor(void* data);
	static FStorage* __cdecl StaticCreateStorage(const FName& name);
	static void __cdecl StaticExit();
	static FStorage* __cdecl StaticFindStorage(const FName& name);
	static FClass* __cdecl StaticGetClass();
	static FString __cdecl StaticGetStorageName(const wchar_t*);
	static void __cdecl StaticInit();
	static FObject* __cdecl StaticLoadObject(const char*, const char*, unsigned int);
	static FStorage* __cdecl StaticLoadStorage(const wchar_t*, int);
	//static int __cdecl StaticLoadStorageObjects(const wchar_t*, FTArray<FObject*>*, unsigned int);
	static int __cdecl StaticNameTableCodecFromClass(FClass* fclass);
	static void __cdecl StaticUnregisterClass();


	int storageFlags;
	FClass* objectCodec;
	FClass* nameCodec;
	Archive* archive;
	FString filePath;
	unsigned int storageVersion;
	unsigned int unk40;
	HeaderV2 headerV2;
	int unk8C;
	unsigned int unk90;
	unsigned int unk94;
	int* unk98;
	int objectsCountV2;
	int unkA0;
	int unkA4;
	unsigned int* unkA8;
	int unkAC[0x16];
	unsigned char unk104[0x48];
	int unk14C[0x1E];
	HeaderV3 headerV3;
	int objectsCountV3;
	int unk208;
	int unk20C;
	ObjectInfoV3* objectsV3;
	int objNamesCount;
	int unk218;
	int unk21C;
	Name* objNames;
	int classNamesCount;
	int unk228;
	int unk22C;
	Name* classNames;
	unsigned char unk234[0x40];
	unsigned char unk274[0x10];
	unsigned char unk284[0x10];
	unsigned char unk294[0x10];

protected:

	unsigned long long GetUniqueValueV2(const FObject*);
	FObject* LoadObject(int, unsigned int);
	void ReadTablesV2();
	void ReadTablesV3();
	void RegisterObjectV2(FObject*);
	int ConvertStorage(FClass*);
	//int CopyObjectsV3(Archive*, Archive*, FTArray<ObjectInfoV3>&);
	void DeleteChildObjectsV2(unsigned long long);
	void DeleteChildObjectsV3(unsigned long, unsigned int);
	void UnregisterObjectV2(FObject*);
	int WriteHeaderV3(Archive* arc, HeaderV3* header);
	//int WriteNameTableV3(Archive*, FTArray<NameV3>&);
	//int WriteObjectInfoV3(Archive*, FTArray<ObjectInfoV3>&);
	//int WriteObjectsV3(Archive*, FTArray<FObject*>&, FTArray<ObjectInfoV3>&);

	static void __cdecl StaticAddStorage(FStorage*);
	static void __cdecl StaticReadName(FArchive* arc, char*);
	static void __cdecl StaticRemoveStorage(FStorage*);
	static void __cdecl StaticWriteName(FArchive* arc, const char*);

	static FMutex ms_Mutex;
	//static FTArray<FString> ms_aSearchPatterns;
	//static FTMap<int, FStorage*> ms_mapStorageMap;

private:

	static FClass* __cdecl StaticConstructClassFStorage();
	static void __cdecl StaticInitClassFStorage();

	static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FStorage, 0x2A8);
