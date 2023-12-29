#pragma once

#include "faktum/api.hpp"
#include "property.hpp"


class FBoolProperty : public FProperty {

public:

	FBoolProperty(const FBoolProperty& other);
	FBoolProperty(unsigned int offset, const FName& group, unsigned int flags, unsigned int bitmask);

	~FBoolProperty() override;

	FBoolProperty& operator=(const FBoolProperty& other);

	using FObject::operator new;
	using FObject::operator delete;
	static void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags);

	void CopyValue(void* dest, void* src) const override;
	BOOL Equals(void* a, void* b) const override;
	void ReadValue(FArchive& archive, void* value) const override;
	BOOL SetValue(void* value, const wchar_t* name) const override;
	void WriteValue(FArchive& archive, void* value) const override;

	unsigned int GetBitMask() const;

	static void StaticConstructor(void* data);
	static FClass* StaticGetClass();
	static void StaticUnregisterClass();


	unsigned int bitmask;

protected:

	FBoolProperty();

private:

	static FClass* StaticConstructClassFBoolProperty();
	static void StaticInitClassFBoolProperty();

	FAK_API static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FBoolProperty, 0x44);
