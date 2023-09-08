#pragma once

#include "core.hpp"
#include "refcount.hpp"
#include "name.hpp"


class FClass;
class FArchive;
class FProperty;
class FTextDevice;
class FEvent;
class FMutex;

class FAK_IMPORT FObject : public FRefCount { // TODO Members, static members

public:

	enum LANGUAGE {}; // TODO Contents

	enum ROUTING {}; // TODO Contents

	using EventHandlerT = void (FObject::*)(FObject*, void*);


	FObject();
	FObject(const FObject& other);

	~FObject() override;

	FObject& operator=(const FObject& other);

	static void* __cdecl operator new(size_t, FObject*, const FName&, const FName&, unsigned int);
	static void __cdecl operator delete(void* ptr);
	static void __cdecl operator delete(void*, FObject*, const FName&, const FName&, unsigned int);

	virtual FObject* Clone(const FName&, const FName&, FObject*, int);
	virtual void Register();
	virtual void Unregister();
	virtual void Serialize(FArchive& archive);
	virtual void PostLoad();
	virtual void PropertyChanged(FProperty* property);
	virtual void Dump(FTextDevice* textDevice);
	virtual void SetStorage(const FName& name);

	FProperty* FindProperty(const FName&) const;
	FClass* GetClass() const;
	int GetEventHandler(int, FObject**, EventHandlerT*);
	int GetIndex() const;
	LANGUAGE GetLanguage() const;
	FName GetName() const;
	unsigned int GetObjectFlags() const;
	const char* GetObjectPath() const;
	FObject* GetOuter() const;
	FName GetStorage() const;
	int HandleEvent(FEvent*, FObject*, void*);
	BOOL IsInstanceOf(FClass* fclass);
	BOOL IsKindOf(FClass* fclass);
	void SetClass(FClass* fclass);
	void SetDirtyStorage();
	int SetEventHandler(int, FObject*, EventHandlerT);
	void SetLanguage(LANGUAGE language);
	void SetName(const FName& name);
	void SetOuter(FObject*);
	int SetProperty(const FName&, const wchar_t*);

	static FObject* __cdecl StaticAllocateObject(FClass*, FObject*, const FName&, const FName&, unsigned int);
	static FObject* __cdecl StaticConstructObject(FClass*, FObject*, const FName&, const FName&, unsigned int);
	static void __cdecl StaticConstructor(void* data);
	static void __cdecl StaticDumpObjects(FTextDevice* textDevice);
	static void __cdecl StaticExit();
	static void __cdecl StaticExitClass();
	static int __cdecl StaticExportObject(FObject*, const wchar_t*, FClass*, FObject*);
	static FObject* __cdecl StaticFindObject(FClass*, FObject*, const FName&, const FName&, int, unsigned int);
	static FClass* __cdecl StaticGetClass();
	static LANGUAGE __cdecl StaticGetLanguage();
	static FObject* __cdecl StaticGetObject(int);
	static FObject* __cdecl StaticImportObject(const wchar_t*, FClass*, FObject*, const FName&, const FName&, FObject*, FObject*);
	static void __cdecl StaticInit();
	static void __cdecl StaticInitClass();
	static void __cdecl StaticSetLanguage(LANGUAGE language);
	static void __cdecl StaticUnregisterClass();


	FClass* objClass;
	int unkC;
	FObject* unk10;
	int unk14;
	FName objName;
	FName className;
	unsigned int objFlags;
	LANGUAGE language;

protected:

	int RegisterEvent(FClass*, const FName&, unsigned int, ROUTING);

private:

	FObject(const char*);

	static FClass* __cdecl StaticConstructClassFObject();
	static void __cdecl StaticInitClassFObject();

	static FObject** ms_apObjHash;
	//static FTArray<FObject*> ms_apObjects;
	static LANGUAGE ms_eLanguage;
	//static FTList<int> ms_lnObjIndices;
	static FMutex ms_mMutex;
	static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FObject, 0x28);
