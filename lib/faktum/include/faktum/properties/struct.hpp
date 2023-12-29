#pragma once

#include "faktum/api.hpp"
#include "property.hpp"


class FStructProperty : public FProperty {

public:

	FStructProperty(const FStructProperty& other);
	FStructProperty(unsigned int offset, const FName& group, FStruct* fstruct);

	~FStructProperty() override;

	FStructProperty& operator=(const FStructProperty& other);

	using FObject::operator new;
	using FObject::operator delete;
	static void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags);

	void CopyValue(void* dest, void* src) const override;
	BOOL Equals(void* a, void* b) const override;
	void ReadValue(FArchive& archive, void* value) const override;
	BOOL SetValue(void* value, const wchar_t* name) const override;
	void WriteValue(FArchive& archive, void* value) const override;

	FStruct* GetStruct();

	static void StaticConstructor(void* data);
	static FClass* StaticGetClass();
	static void StaticUnregisterClass();


	FStruct* fstruct;

protected:

	FStructProperty();

private:

	static FClass* StaticConstructClassFStructProperty();
	static void StaticInitClassFStructProperty();

	FAK_API static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FStructProperty, 0x44);
