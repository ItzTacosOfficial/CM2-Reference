#pragma once

#include "faktum/api.hpp"
#include "property.hpp"



class FIntProperty : public FProperty {

public:

	FIntProperty(const FIntProperty& other);
	FIntProperty(unsigned int offset, const FName& group, int min, int max, int step);
	FIntProperty(unsigned int offset, const FName& group, unsigned int flags);

	~FIntProperty() override;

	FIntProperty& operator=(const FIntProperty& other);

	using FObject::operator new;
	using FObject::operator delete;
	void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags = 0);

	void CopyValue(void* dest, void* src) const override;
	BOOL Equals(void* a, void* b) const override;
	void ReadValue(FArchive& archive, void* data) const override;
	BOOL SetValue(void* data, const wchar_t* value) const override;
	void WriteValue(FArchive& archive, void* data) const override;

	int GetMaxValue() const;
	int GetMinValue() const;
	int GetStepSize() const;

	static void StaticConstructor(void* data);
	static FClass* StaticGetClass();
	static void StaticUnregisterClass();


	int minValue;
	int maxValue;
	int stepSize;

protected:

	FIntProperty();

private:

	static FClass* StaticConstructClassFIntProperty();
	static void StaticInitClassFIntProperty();

	FAK_API static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FIntProperty, 0x4C);
