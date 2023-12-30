#pragma once

#include "faktum/api.hpp"
#include "property.hpp"


class FEnumProperty : public FProperty {

public:

	struct Enumerator {

		FName name;
		int value;

	};
	FAK_SIZE_GUARD(Enumerator, 0x8);


	FEnumProperty(const FEnumProperty& other);
	FEnumProperty(unsigned int size, const FName& group, FTArray<Enumerator> const& enumerators, unsigned int flags);

	~FEnumProperty() override;

	FEnumProperty& operator=(const FEnumProperty& other);

	using FObject::operator new;
	using FObject::operator delete;
	static void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags);

	void CopyValue(void* dest, void* src) const override;
	BOOL Equals(void* a, void* b) const override;
	void ReadValue(FArchive& archive, void* data) const override;
	BOOL SetValue(void* data, const wchar_t* value) const override;
	void WriteValue(FArchive& archive, void* data) const override;

	int GetEnumeratorCount();
	const FName& GetEnumeratorName(int index);
	int GetEnumeratorValue(int index);

	static void StaticConstructor(void* data);
	static FClass* StaticGetClass();
	static void StaticUnregisterClass();


	FTArray<Enumerator> enumerators;

protected:

	FEnumProperty();

private:

	static FClass* StaticConstructClassFEnumProperty();
	static void StaticInitClassFEnumProperty();

	FAK_API static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FEnumProperty, 0x50);
