#pragma once

#include "faktum/api.hpp"
#include "refcount.hpp"
#include "faktum/util/array.hpp"
#include "faktum/core/memmanager.hpp"
#include "name.hpp"


class FClass;
class FArchive;
class FProperty;
class FTextDevice;
class FEvent;
class FMutex;

class FObject : public FRefCount { // TODO List

public:

	struct FAK_ASSUMED FindData {

		int index;
		FClass* fclass;

	};
	FAK_SIZE_GUARD(FindData, 0x8);

	enum LANGUAGE { // TODO Contents
		LANG_DEFAULT = -1
	};

	enum ROUTING { // TODO Contents
		ROUTING_UNK = 2
	};

	using EventHandlerT = void (FObject::*)(FObject* userObject, void* userData);


	FObject();
	FObject(const FObject& other);

	~FObject() override;

	FObject& operator=(const FObject& other);

	FAK_ASSUMED static inline void* operator new(size_t size) {
		return FtGetMemManager()->Alloc(size, L"new");
	}

	static void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags = 0);
	static void operator delete(void* ptr);
	static void operator delete(void* ptr, FObject* outer, const FName& object, const FName& storage, unsigned int flags);

	virtual FObject* Clone(const FName& object, const FName& storage, FObject*, int);
	virtual void Register();
	virtual void Unregister();
	virtual void Serialize(FArchive& archive);
	virtual void PostLoad();
	virtual void PropertyChanged(FProperty* property);
	virtual void Dump(FTextDevice* textDevice);
	virtual void SetStorage(const FName& name);

	FProperty* FindProperty(const FName& name) const;
	FClass* GetClass() const;
	BOOL GetEventHandler(int eventID, FObject** userObject, EventHandlerT* handler);
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
	BOOL SetProperty(const FName& name, const wchar_t* value);

	static FObject* StaticAllocateObject(FClass* fclass, FObject* outer, const FName& object, const FName& storage, unsigned int flags = 0);
	static FObject* StaticConstructObject(FClass* fclass, FObject* outer, const FName& object, const FName& storage, unsigned int flags = 0);
	static void StaticConstructor(void* data);
	static void StaticDumpObjects(FTextDevice* textDevice);
	static void StaticExit();
	static void StaticExitClass();
	static BOOL StaticExportObject(FObject* object, const wchar_t* path, FClass* exportClass = nullptr, FObject* param = nullptr);
	static FObject* StaticFindObject(FClass* fclass, FObject* outer, const FName& object, const FName& storage, BOOL exactClass, unsigned int language = LANG_DEFAULT);
	static FClass* StaticGetClass();
	static LANGUAGE StaticGetLanguage();
	static FObject* StaticGetObject(int index);
	static FObject* StaticImportObject(const wchar_t* path, FClass* fclass, FObject* outer, const FName& object, const FName& storage, FObject* = nullptr, FObject* = nullptr);
	static void StaticInit();
	static void StaticInitClass();
	static void StaticSetLanguage(LANGUAGE language);
	static void StaticUnregisterClass();

	FAK_INLINED static inline BOOL StaticIsIndexValid(const int& index) {

		ms_mMutex.Enter();

		const BOOL valid = index < ms_apObjects.GetLength();

		ms_mMutex.Leave();

		return valid;

	}

	FAK_INLINED static inline void StaticFindObjectIndex(FindData& data) {

		ms_mMutex.Enter();

		BOOL found = FALSE;

		do {

			FObject* object;

			do {

				data.index++;

				if (data.index >= ms_apObjects.GetLength()) {
					ms_mMutex.Leave();
					return;
				}

				object = ms_apObjects[data.index];

			} while (!object);

			found = object->IsKindOf(data.fclass);

		} while (!found);

		ms_mMutex.Leave();

	}


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

	FAK_API static FObject* ms_apObjHash[4096];
	FAK_API static FTArray<FObject*> ms_apObjects;
	FAK_API static LANGUAGE ms_eLanguage;
	FAK_API static FTList<int> ms_lnObjIndices;
	FAK_API static FMutex ms_mMutex;
	FAK_API static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FObject, 0x28);


#define FAK_OBJ_DEFINE(class, super) FAK_ASSUMED	\
													\
public:												\
													\
using FObject::operator new;						\
using FObject::operator delete;						\
													\
static void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags = 0) {	\
	return FObject::StaticAllocateObject(StaticGetClass(), outer, object, storage, flags);	\
}													\
													\
static void StaticConstructor(void* data) {			\
	reinterpret_cast<class*>(data)->class::class();	\
}													\
													\
static FClass* StaticGetClass() {					\
													\
	if (!ms_pClass) {								\
		ms_pClass = StaticConstructClass##class();	\
		StaticInitClass##class();					\
	}												\
													\
	return ms_pClass;								\
													\
}													\
													\
static void StaticUnregisterClass() {				\
													\
	if (ms_pClass) {								\
		delete ms_pClass;							\
		ms_pClass = nullptr;						\
	}												\
													\
}													\
													\
private:											\
													\
static FClass* StaticConstructClass##class() {		\
	return new FClass(#class, sizeof(class), &StaticConstructor, &StaticInitClass);	\
}													\
													\
static void StaticInitClass##class() {				\
													\
	FClass* self = StaticGetClass();				\
													\
	self->superStruct = super::StaticGetClass();	\
	self->objectClass = FClass::StaticGetClass();	\
													\
	self->Register();								\
													\
}													\
													\
static inline FClass* ms_pClass /* User ; */

#define FAK_OBJ_REGISTER_EVENT(eventid, name, routing) FAK_ASSUMED	\
																	\
if (eventid == -1) {												\
	eventid = RegisterEvent(StaticGetClass(), name, sizeof(decltype(*this)), routing);	\
}																	\
do {} while (false) /* User ; */
