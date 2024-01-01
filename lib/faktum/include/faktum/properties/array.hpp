#pragma once

#include "faktum/api.hpp"
#include "property.hpp"


class FArrayProperty : public FProperty {

public:

	FArrayProperty(const FArrayProperty& other);
	FArrayProperty(unsigned int offset, const FName& group, FProperty* elementProperty);

	~FArrayProperty() override;

	FArrayProperty& operator=(const FArrayProperty& other);

	using FObject::operator new;
	using FObject::operator delete;
	static void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags = 0);

	void CopyValue(void* dest, void* src) const override;
	BOOL Equals(void* a, void* b) const override;
	void ReadValue(FArchive& archive, void* data) const override;
	BOOL SetValue(void* data, const wchar_t* value) const override;
	void WriteValue(FArchive& archive, void* data) const override;

	FProperty* GetElementProperty() const;

	static void StaticConstructor(void* data);
	static FClass* StaticGetClass();
	static void StaticUnregisterClass();


	FProperty* elementProperty;

protected:

	FArrayProperty();

private:

	static FClass* StaticConstructClassFArrayProperty();
	static void StaticInitClassFArrayProperty();

	FAK_API static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FArrayProperty, 0x44);
