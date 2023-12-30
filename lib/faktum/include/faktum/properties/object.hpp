#pragma once

#include "faktum/api.hpp"
#include "property.hpp"


class FObjectProperty : public FProperty {

public:

	FObjectProperty(const FObjectProperty& other);
	FObjectProperty(unsigned int offset, const FName& group, FClass* objectClass, unsigned int flags);

	~FObjectProperty() override;

	FObjectProperty& operator=(const FObjectProperty& other);

	using FObject::operator new;
	using FObject::operator delete;
	static void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags);

	void CopyValue(void* dest, void* src) const override;
	void DestroyValue(void* value) const override;
	BOOL Equals(void* a, void* b) const override;
	void ReadValue(FArchive& archive, void* data) const override;
	BOOL SetValue(void* data, const wchar_t* value) const override;
	void WriteValue(FArchive& archive, void* data) const override;

	FClass* GetObjectClass();

	static void StaticConstructor(void* data);
	static FClass* StaticGetClass();
	static void StaticUnregisterClass();


	FClass* objectClass;

protected:

	FObjectProperty();

private:

	static FClass* StaticConstructClassFObjectProperty();
	static void StaticInitClassFObjectProperty();

	FAK_API static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FObjectProperty, 0x44);
