#pragma once

#include "core.hpp"
#include "refcount.hpp"
#include "memmanager.hpp"
#include "name.hpp"


class FClass;
class FArchive;
class FProperty;
class FTextDevice;
class FEvent;
class FMutex;

class /*FAK_IMPORT*/ FObject : public FRefCount { // TODO Members, static members

public:

	enum LANGUAGE {}; // TODO Contents

	enum ROUTING { // TODO Contents
		UNKROUTING = 2
	};

	using EventHandlerT = void (FObject::*)(FObject* userObject, void* userData);


	FObject();
	FObject(const FObject& other);

	~FObject() override;

	FObject& operator=(const FObject& other);

	FAK_ASSUMED static inline void* operator new(size_t size) {
		return FtGetMemManager()->Alloc(size, L"new");
	}

	static void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags);
	static void operator delete(void* ptr);
	static void operator delete(void* ptr, FObject* outer, const FName& object, const FName& storage, unsigned int flags);

	virtual FObject* Clone(const FName&, const FName&, FObject*, int);
	virtual void Register();
	virtual void Unregister();
	virtual void Serialize(FArchive& archive);
	virtual void PostLoad();
	virtual void PropertyChanged(FProperty* property);
	virtual void Dump(FTextDevice* textDevice);
	virtual void SetStorage(const FName& name);

	FProperty* FindProperty(const FName& name) const;
	FClass* GetClass() const;
	BOOL GetEventHandler(int, FObject**, EventHandlerT*);
	int GetIndex() const;
	LANGUAGE GetLanguage() const;
	FName GetName() const;
	unsigned int GetObjectFlags() const;
	const char* GetObjectPath() const;
	FObject* GetOuter() const;
	FName GetStorage() const;
	BOOL HandleEvent(FEvent* event, FObject* userObject, void* userData);
	BOOL IsInstanceOf(FClass* fclass);
	BOOL IsKindOf(FClass* fclass);
	void SetClass(FClass* fclass);
	void SetDirtyStorage();
	BOOL SetEventHandler(int eventID, FObject* userObject, EventHandlerT handler);
	void SetLanguage(LANGUAGE language);
	void SetName(const FName& name);
	void SetOuter(FObject* outer);
	int SetProperty(const FName&, const wchar_t*);

	static FObject* StaticAllocateObject(FClass* fclass, FObject* outer, const FName& object, const FName& storage, unsigned int flags);
	static FObject* StaticConstructObject(FClass* fclass, FObject* outer, const FName& object, const FName& storage, unsigned int flags);
	static void StaticConstructor(void* data);
	static void StaticDumpObjects(FTextDevice* textDevice);
	static void StaticExit();
	static void StaticExitClass();
	static int StaticExportObject(FObject*, const wchar_t*, FClass*, FObject*);
	static FObject* StaticFindObject(FClass*, FObject*, const FName&, const FName&, int, unsigned int);
	static FClass* StaticGetClass();
	static LANGUAGE StaticGetLanguage();
	static FObject* StaticGetObject(int index);
	static FObject* StaticImportObject(const wchar_t* path, FClass*, FObject*, const FName&, const FName&, FObject*, FObject*);
	static void StaticInit();
	static void StaticInitClass();
	static void StaticSetLanguage(LANGUAGE language);
	static void StaticUnregisterClass();


	FClass* objectClass;
	int objectIndex;
	FObject* outerObject;
	FObject* lookupNextObject;
	FName objectName;
	FName storageName;
	unsigned int objectFlags;
	LANGUAGE objectLanguage;

protected:

	int RegisterEvent(FClass* fclass, const FName& name, unsigned int objectSize, ROUTING routing);

private:

	FObject(const char* name);

	static FClass* StaticConstructClassFObject();
	static void StaticInitClassFObject();

	static FObject* ms_apObjHash[4096];
	static FTArray<FObject*> ms_apObjects;
	static LANGUAGE ms_eLanguage;
	//static FTList<int> ms_lnObjIndices;
	static FMutex ms_mMutex;
	static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FObject, 0x28);
