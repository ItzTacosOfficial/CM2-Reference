#pragma once

#include "core.hpp"
#include "archive.hpp"


class FObject;
class FName;
class FTextDevice;
class FClass;
class FString;
class FMutex;

class FAK_IMPORT FStorage { // TODO Members, static members, functions, size

public:

	class Archive : public FArchive { // TODO Contents



	};

	struct FAK_ASSUMED Name {
		char* str;
		unsigned int nameLength;
	};

	struct HeaderV3 { // TODO Contents



	};

	struct FAK_ASSUMED ObjectInfoV3 { // TODO Contents



	};


	FStorage(FStorage const& other);
	FStorage();

	virtual ~FStorage();

	static void* __cdecl operator new(unsigned int, FObject*, FName const&, FName const&, unsigned int);

	FStorage& operator=(FStorage const& other);

	virtual void Dump(FTextDevice* textDevice);

	int DeleteObject(char const*, unsigned int);
	void Empty();
	int FindObject(char const*, FClass*, unsigned int);
	wchar_t const* GetFilePath(); const;
	FClass const* GetNameCodecClass(); const;
	char const* GetObjectClass(int id); const;
	FClass const* GetObjectCodecClass(); const;
	int GetObjectCount(); const;
	char const* GetObjectGroup(int id); const;
	unsigned int GetObjectLanguage(int id); const;
	FString GetObjectMD5(int id); const;
	char const* GetObjectName(int id); const;
	unsigned int GetStorageFlags(); const;
	int Load(wchar_t const* path);
	FObject* LoadObject(char const*, FClass*, unsigned int);
	int ReloadObject(FObject* object);
	int RenameObject(int id, char const* name);
	void Revert();
	int Save(wchar_t const* path);
	void SetFilePath(wchar_t const* path);
	void SetNameCodec(FClass* fclass);
	void SetObjectCodec(FClass* fclass);
	void SetObjectGroup(int, FName const&);
	void SetStorageFlags(unsigned int flags);

	static int __cdecl StaticAddSearchPattern(wchar_t const*);
	static FClass* __cdecl StaticClassFromNameTableCodec(int);
	static void __cdecl StaticConstructor(void* data);
	static FStorage* __cdecl StaticCreateStorage(FName const& name);
	static void __cdecl StaticExit();
	static FStorage* __cdecl StaticFindStorage(FName const& name);
	static FClass* __cdecl StaticGetClass();
	static FString __cdecl StaticGetStorageName(wchar_t const*);
	static void __cdecl StaticInit();
	static FObject* __cdecl StaticLoadObject(char const*, char const*, unsigned int);
	static FStorage* __cdecl StaticLoadStorage(wchar_t const*, int);
	//static int __cdecl StaticLoadStorageObjects(wchar_t const*, FTArray<FObject*>*, unsigned int);
	static int __cdecl StaticNameTableCodecFromClass(FClass* fclass);
	static void __cdecl StaticUnregisterClass();

protected:

	unsigned long long GetUniqueValueV2(FObject const*);
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
	static void __cdecl StaticWriteName(FArchive* arc, char const*);

	static FMutex ms_Mutex;
	//static FTArray<FString> ms_aSearchPatterns;
	//static FTMap<int, FStorage*> ms_mapStorageMap;

private:

	static FClass* __cdecl StaticConstructClassFStorage();
	static void __cdecl StaticInitClassFStorage();

	static FClass* ms_pClass;

};
