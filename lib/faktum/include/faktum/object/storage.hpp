#pragma once

#include "faktum/api.hpp"
#include "object.hpp"
#include "faktum/util/archive.hpp"
#include "faktum/util/string.hpp"
#include "faktum/util/array.hpp"


class FCodec;
class FObject;
class FName;
class FTextDevice;
class FClass;
class FMutex;

class FStorage : public FObject { // TODO Members, static members, functions

public:

	class Archive : public FArchive { // TODO Verify

	public:

		BOOL Close() override;
		unsigned int Read(void* dest, unsigned int size) override;
		unsigned int Write(const void* src, unsigned int size) override;
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
		FObject::LANGUAGE objectLanguage;

	};
	FAK_SIZE_GUARD(Archive, 0x1C);

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
	FAK_SIZE_GUARD(HeaderV2, 0x48);

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
	FAK_SIZE_GUARD(HeaderV3, 0x40);

	struct NameV3 {

		char* string;
		unsigned int length;

	};
	FAK_SIZE_GUARD(NameV3, 0x8);

	struct FAK_ASSUMED ObjectInfoV2 {

		unsigned int unk0[2];
		unsigned int nameIndex;
		unsigned int classIndex;
		unsigned int unk10[4];
		unsigned int groupIndex;
		unsigned int unk24[17];

	};
	FAK_SIZE_GUARD(ObjectInfoV2, 0x68);

	struct ObjectInfoV3 { // TODO Contents

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
	FAK_SIZE_GUARD(ObjectInfoV3, 0x30);


	FStorage(const FStorage& other);
	FStorage();

	~FStorage() override;

	using FObject::operator new;
	using FObject::operator delete;
	static void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags);

	FStorage& operator=(const FStorage& other);

	void Dump(FTextDevice* textDevice) override;

	BOOL DeleteObject(const char* object, unsigned int language);
	void Empty();
	int FindObject(const char* name, FClass* fclass, unsigned int language);
	const wchar_t* GetFilePath() const;
	const FClass* GetNameCodecClass() const;
	const char* GetObjectClass(int id) const;
	const FClass* GetObjectCodecClass() const;
	int GetObjectCount() const;
	const char* GetObjectGroup(int id) const; // Unimplemented
	unsigned int GetObjectLanguage(int id) const;
	FString GetObjectMD5(int id) const;
	const char* GetObjectName(int id) const;
	unsigned int GetStorageFlags() const;
	BOOL Load(const wchar_t* path);
	FObject* LoadObject(const char* name, FClass* fclass, unsigned int language);
	BOOL ReloadObject(FObject* object);
	BOOL RenameObject(int id, const char* name); // Unimplemented
	void Revert();
	BOOL Save(const wchar_t* path);
	void SetFilePath(const wchar_t* path);
	void SetNameCodec(FClass* codec);
	void SetObjectCodec(FClass* codec);
	void SetObjectGroup(int id, const FName& name);
	void SetStorageFlags(unsigned int flags);

	static int StaticAddSearchPattern(const wchar_t* pattern);
	static FClass* StaticClassFromNameTableCodec(BOOL zip);
	static void StaticConstructor(void* data);
	static FStorage* StaticCreateStorage(const FName& name);
	static void StaticExit();
	static FStorage* StaticFindStorage(const FName& name);
	static FClass* StaticGetClass();
	static FString StaticGetStorageName(const wchar_t* path);
	static void StaticInit();
	static FObject* StaticLoadObject(const char* storageName, const char* object, unsigned int language);
	static FStorage* StaticLoadStorage(const wchar_t* path, BOOL);
	static BOOL StaticLoadStorageObjects(const wchar_t* path, FTArray<FObject*>* objects, unsigned int language);
	static BOOL StaticNameTableCodecFromClass(FClass* codec);
	static void StaticUnregisterClass();


	int storageFlags;
	FClass* objectCodec;
	FClass* nameCodec;
	Archive* storageArchive;
	FString storagePath;
	unsigned int storageVersion;
	int unused40;
	HeaderV2 headerV2;
	FTArray<FName> namesV2;
	FTArray<ObjectInfoV2> objectsV2;
	unsigned int unkAC[22]; // Unknown V2 FTArrays
	HeaderV2 previousHeaderV2;
	unsigned int unk14C[30]; // More Unknown V2 FTArrays
	HeaderV3 headerV3;
	FTArray<ObjectInfoV3> objectsV3;
	FTArray<NameV3> objectNamesV3;
	FTArray<NameV3> classNamesV3;
	HeaderV3 previousHeaderV3;
	FTArray<ObjectInfoV3> previousObjectsV3;
	FTArray<NameV3> previousObjectNamesV3;
	FTArray<NameV3> previousClassNamesV3;

protected:

	unsigned long long GetUniqueValueV2(const FObject* object);
	FObject* LoadObject(int id, unsigned int language);
	void ReadTablesV2();
	void ReadTablesV3();
	void RegisterObjectV2(FObject* object);
	BOOL ConvertStorage(FClass* codec);
	BOOL CopyObjectsV3(Archive*, Archive*, FTArray<ObjectInfoV3>&);
	void DeleteChildObjectsV2(unsigned long long);
	void DeleteChildObjectsV3(unsigned long, unsigned int);
	void UnregisterObjectV2(FObject* object);
	BOOL WriteHeaderV3(Archive* archive, HeaderV3* header);
	BOOL WriteNameTableV3(Archive* archive, FTArray<NameV3>& names);
	BOOL WriteObjectInfoV3(Archive* archive, FTArray<ObjectInfoV3>& infos);
	BOOL WriteObjectsV3(Archive* archive, FTArray<FObject*>& objects, FTArray<ObjectInfoV3>& infos);

	static void StaticAddStorage(FStorage* storage);
	static void StaticReadName(FArchive* archive, char* out);
	static void StaticRemoveStorage(FStorage* storage);
	static void StaticWriteName(FArchive* archive, const char* name);

	FAK_API static FMutex ms_Mutex;
	FAK_API static FTArray<FString> ms_aSearchPatterns;
	//FAK_API static FTMap<int, FStorage*> ms_mapStorageMap;

private:

	static FClass* StaticConstructClassFStorage();
	static void StaticInitClassFStorage();

	FAK_API static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FStorage, 0x2A8);
