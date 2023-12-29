#pragma once

#include "faktum/api.hpp"
#include "property.hpp"


class FTimeProperty : public FProperty {

public:

	FTimeProperty(const FTimeProperty& other);
	FTimeProperty(unsigned int offset, const FName& group);

	~FTimeProperty() override;

	FTimeProperty& operator=(const FTimeProperty& other);

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

	FTimeProperty();

private:

	static FClass* StaticConstructClassFTimeProperty();
	static void StaticInitClassFTimeProperty();

	FAK_API static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FTimeProperty, 0x40);
