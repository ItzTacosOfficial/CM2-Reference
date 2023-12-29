#pragma once

#include "faktum/api.hpp"
#include "property.hpp"


class FColorProperty : public FProperty {

public:

	FColorProperty(const FColorProperty& other);
	FColorProperty(unsigned int offset, const FName& group);

	~FColorProperty() override;

	FColorProperty& operator=(const FColorProperty& other);

	using FObject::operator new;
	using FObject::operator delete;
	static void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags);

	void CopyValue(void* dest, void* src) const override;
	BOOL Equals(void* a, void* b) const override;
	void ReadValue(FArchive& archive, void* value) const override;
	BOOL SetValue(void* value, const wchar_t* name) const override;
	void WriteValue(FArchive& archive, void* value) const override;

	static void StaticConstructor(void* data);
	static FClass* StaticGetClass();
	static void StaticUnregisterClass();

protected:

	FColorProperty();

private:

	static FClass* StaticConstructClassFColorProperty();
	static void StaticInitClassFColorProperty();

	FAK_API static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FColorProperty, 0x40);
