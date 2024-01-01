#pragma once

#include "faktum/api.hpp"
#include "property.hpp"


class FFloatProperty : public FProperty {

public:

	FFloatProperty(const FFloatProperty& other);
	FFloatProperty(unsigned int offset, const FName& group);
	FFloatProperty(unsigned int offset, const FName& group, float min, float max, float step);

	~FFloatProperty() override;

	FFloatProperty& operator=(const FFloatProperty& other);

	using FObject::operator new;
	using FObject::operator delete;
	static void* operator new(size_t size, FObject* outer, const FName& object, const FName& storage, unsigned int flags = 0);

	void CopyValue(void* dest, void* src) const override;
	BOOL Equals(void* a, void* b) const override;
	void ReadValue(FArchive& archive, void* data) const override;
	BOOL SetValue(void* data, const wchar_t* value) const override;
	void WriteValue(FArchive& archive, void* data) const override;

	float GetMaxValue() const;
	float GetMinValue() const;
	float GetStepSize() const;

	static void StaticConstructor(void* data);
	static FClass* StaticGetClass();
	static void StaticUnregisterClass();


	float minValue;
	float maxValue;
	float stepSize;

protected:

	FFloatProperty();

private:

	static FClass* StaticConstructClassFFloatProperty();
	static void StaticInitClassFFloatProperty();

	FAK_API static FClass* ms_pClass;

};
FAK_SIZE_GUARD(FFloatProperty, 0x4C);
