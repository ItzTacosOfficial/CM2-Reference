#pragma once

#include "faktum/api.hpp"
#include "property.hpp"



class FInt64Property : public FProperty {

public:

	FInt64Property(const FInt64Property& other);
	FInt64Property(unsigned int offset, const FName& group);

	~FInt64Property() override;

	FInt64Property& operator=(const FInt64Property& other);

	using FObject::operator new;
	using FObject::operator delete;
	void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags = 0);

	void CopyValue(void* dest, void* src) const override;
	BOOL Equals(void* a, void* b) const override;
	void ReadValue(FArchive& archive, void* data) const override;
	BOOL SetValue(void* data, const wchar_t* value) const override;
	void WriteValue(FArchive& archive, void* data) const override;

	static void StaticConstructor(void* data);
	static FClass* StaticGetClass();
	static void StaticUnregisterClass();

protected:

	FInt64Property();

private:

	static FClass* StaticConstructClassFInt64Property();
	static void StaticInitClassFInt64Property();

	FAK_API static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FInt64Property, 0x40);
