#pragma once

#include "faktum/api.hpp"
#include "property.hpp"


class FQuaternionProperty : public FProperty {

public:

	FQuaternionProperty(const FQuaternionProperty& other);
	FQuaternionProperty(unsigned int offset, const FName& group);

	~FQuaternionProperty() override;

	FQuaternionProperty& operator=(const FQuaternionProperty& other);

	using FObject::operator new;
	using FObject::operator delete;
	static void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags);

	void CopyValue(void* dest, void* src) const override;
	BOOL Equals(void* a, void* b) const override;
	void ReadValue(FArchive& archive, void* data) const override;
	BOOL SetValue(void* data, const wchar_t* value) const override;
	void WriteValue(FArchive& archive, void* data) const override;

	static void StaticConstructor(void* data);
	static FClass* StaticGetClass();
	static void StaticUnregisterClass();

protected:

	FQuaternionProperty();

private:

	static FClass* StaticConstructClassFQuaternionProperty();
	static void StaticInitClassFQuaternionProperty();

	FAK_API static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FQuaternionProperty, 0x40);
