#pragma once

#include "faktum/api.hpp"
#include "property.hpp"



class FStringProperty : public FProperty {

public:

	FStringProperty(const FStringProperty& other);
	FStringProperty(unsigned int offset, const FName& group);
	FStringProperty(unsigned int offset, const FName& group, unsigned int maxChars);

	~FStringProperty() override;

	FStringProperty& operator=(const FStringProperty& other);

	using FObject::operator new;
	using FObject::operator delete;
	void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags = 0);

	void CopyValue(void* dest, void* src) const override;
	BOOL Equals(void* a, void* b) const override;
	void ReadValue(FArchive& archive, void* data) const override;
	BOOL SetValue(void* data, const wchar_t* value) const override;
	void WriteValue(FArchive& archive, void* data) const override;

	unsigned int GetMaxChars() const;

	static void StaticConstructor(void* data);
	static FClass* StaticGetClass();
	static void StaticUnregisterClass();


	unsigned int maxChars;

protected:

	FStringProperty();

private:

	static FClass* StaticConstructClassFStringProperty();
	static void StaticInitClassFStringProperty();

	FAK_API static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FStringProperty, 0x44);
