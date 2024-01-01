#pragma once

#include "faktum/api.hpp"
#include "faktum/object/field.hpp"


class FProperty : public FField {

public:

	enum FAK_ASSUMED FLAG {
		HIDDEN		= 0x1,
		READONLY	= 0x2,
		SELECTED	= 0x4
	};


	FProperty(const FProperty& other);
	FProperty(unsigned int offset, unsigned int size, const FName& group, unsigned int flags);

	~FProperty() override;

	FProperty& operator=(const FProperty& other);

	using FObject::operator new;
	using FObject::operator delete;
	static void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags = 0);

	virtual void CopyValue(void* dest, void* src) const = 0;
	virtual void DestroyValue(void* value) const;
	virtual BOOL Equals(void* a, void* b) const = 0;
	virtual BOOL SetValue(void* data, const wchar_t* value) const = 0;
	virtual void WriteValue(FArchive& archive, void* data) const = 0;
	virtual void ReadValue(FArchive& archive, void* data) const = 0;

	FName GetGroup() const;
	FProperty* GetNextProperty() const;
	unsigned int GetOffset() const;
	unsigned int GetPropertyFlags() const;
	unsigned int GetSize() const;
	BOOL IsHidden() const;
	BOOL IsReadOnly() const;
	BOOL IsSelected() const;
	void Select(BOOL state);

	static FClass* StaticGetClass();
	static void StaticUnregisterClass();


	FName group;
	FProperty* next;
	unsigned int offset;
	unsigned int size;
	unsigned int propertyFlags;

protected:

	FProperty();

private:

	static FClass* StaticConstructClassFProperty();
	static void StaticInitClassFProperty();

	FAK_API static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FProperty, 0x40);
